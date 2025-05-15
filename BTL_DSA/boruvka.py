
import tkinter as tk
from tkinter import messagebox

class GraphDrawer:
    def __init__(self, root):
        self.root = root
        self.root.title("Boruvka Simulation")
        self.canvas = tk.Canvas(root, width=800, height=600, bg="white")
        self.canvas.pack()
 
        # Label to show MST total weight
        self.mst_label = tk.Label(root, text="", font=("Arial", 12))
        self.mst_label.pack()

        # Button frame
        self.button_frame = tk.Frame(root)
        self.button_frame.pack()

        # Buttons
        self.run_button = tk.Button(self.button_frame, text="Run", command=self.run_boruvka)
        self.run_button.pack(side=tk.LEFT, padx=5)
        
        self.restart_button = tk.Button(self.button_frame, text="Khởi động lại", command=self.restart_program)
        self.restart_button.pack(side=tk.LEFT, padx=5)
        
        self.exit_button = tk.Button(self.button_frame, text="Thoát", command=self.exit_program)
        self.exit_button.pack(side=tk.LEFT, padx=5)

        self.vertices = {}  # vertex_id: (x, y, circle_id, label_id)
        self.edges = {}     # (v1, v2): (line_id, entry_widget, entry_window)
        self.vertex_radius = 15
        self.vertex_count = 0

        self.dragging_vertex = None
        self.temp_line = None

        self.canvas.bind("<Button-1>", self.left_click)
        self.canvas.bind("<ButtonRelease-1>", self.left_release)
        self.canvas.bind("<B1-Motion>", self.left_drag)
        self.canvas.bind("<Button-3>", self.right_click)

    def left_click(self, event):
        # Check if clicked on a vertex
        vertex = self.find_vertex(event.x, event.y)
        if vertex is None:
            # Clicked empty space: create new vertex
            self.create_vertex(event.x, event.y)
        else:
            # Start dragging from this vertex to create edge
            self.dragging_vertex = vertex

    def left_drag(self, event):
        if self.dragging_vertex is not None:
            # Draw temporary line from dragging_vertex to current mouse position
            x0, y0, _, _ = self.vertices[self.dragging_vertex]
            if self.temp_line:
                self.canvas.delete(self.temp_line)
            self.temp_line = self.canvas.create_line(x0, y0, event.x, event.y, fill="gray", dash=(4, 2))

    def left_release(self, event):
        if self.dragging_vertex is not None:
            # Check if released on another vertex
            target_vertex = self.find_vertex(event.x, event.y)
            if target_vertex is not None and target_vertex != self.dragging_vertex:
                # Create edge between dragging_vertex and target_vertex
                self.create_edge(self.dragging_vertex, target_vertex)
            # Clear dragging state and temp line
            if self.temp_line:
                self.canvas.delete(self.temp_line)
                self.temp_line = None
            self.dragging_vertex = None

    def right_click(self, event):
        # Check if clicked on vertex
        vertex = self.find_vertex(event.x, event.y)
        if vertex is not None:
            self.delete_vertex(vertex)
            return
        # Check if clicked on edge line
        edge = self.find_edge(event.x, event.y)
        if edge is not None:
            self.delete_edge(edge)

    def create_vertex(self, x, y):
        r = self.vertex_radius
        circle_id = self.canvas.create_oval(x-r, y-r, x+r, y+r, fill="lightblue", outline="black")
        label_id = self.canvas.create_text(x, y, text=str(self.vertex_count), font=("Arial", 12, "bold"))
        self.vertices[self.vertex_count] = (x, y, circle_id, label_id)
        self.vertex_count += 1

    def create_edge(self, v1, v2):
        # Sort vertices to avoid duplicate edges in different order
        edge_key = tuple(sorted((v1, v2)))
        if edge_key in self.edges:
            return  # edge already exists

        def circle_line_intersection(cx, cy, r, x1, y1, x2, y2):
            # Calculate intersection point of line segment (x1,y1)-(x2,y2) with circle centered at (cx,cy) radius r
            from math import sqrt
            dx = x2 - x1
            dy = y2 - y1
            A = dx*dx + dy*dy
            B = 2*(dx*(x1 - cx) + dy*(y1 - cy))
            C = (x1 - cx)**2 + (y1 - cy)**2 - r*r
            det = B*B - 4*A*C
            if A <= 0.0000001 or det < 0:
                return cx, cy  # No intersection, return center as fallback
            sqrt_det = sqrt(det)
            t1 = (-B + sqrt_det) / (2*A)
            t2 = (-B - sqrt_det) / (2*A)
            # Choose t in [0,1]
            t = None
            if 0 <= t1 <= 1:
                t = t1
            elif 0 <= t2 <= 1:
                t = t2
            if t is None:
                return cx, cy
            ix = x1 + t*dx
            iy = y1 + t*dy
            return ix, iy

        x1, y1, _, _ = self.vertices[v1]
        x2, y2, _, _ = self.vertices[v2]
        r = self.vertex_radius

        # Calculate intersection points with vertex circles
        start_x, start_y = circle_line_intersection(x1, y1, r, x1, y1, x2, y2)
        end_x, end_y = circle_line_intersection(x2, y2, r, x2, y2, x1, y1)

        line_id = self.canvas.create_line(start_x, start_y, end_x, end_y, width=2)

        # Create Entry widget for weight at midpoint
        mid_x = (start_x + end_x) / 2
        mid_y = (start_y + end_y) / 2
        entry = tk.Entry(self.root, width=4, justify='center')
        entry.insert(0, "1")
        entry_window = self.canvas.create_window(mid_x, mid_y, window=entry)

        # Bind left click on entry to focus for editing
        entry.bind("<Button-1>", lambda e: entry.focus_set())

        self.edges[edge_key] = (line_id, entry, entry_window)

    def delete_vertex(self, vertex):
        # Delete vertex circle and label
        x, y, circle_id, label_id = self.vertices[vertex]
        self.canvas.delete(circle_id)
        self.canvas.delete(label_id)
        del self.vertices[vertex]

        # Delete all edges connected to this vertex
        edges_to_delete = [edge for edge in self.edges if vertex in edge]
        for edge in edges_to_delete:
            self.delete_edge(edge)

    def delete_edge(self, edge):
        line_id, entry, entry_window = self.edges[edge]
        self.canvas.delete(line_id)
        self.canvas.delete(entry_window)
        entry.destroy()
        del self.edges[edge]

    def find_vertex(self, x, y):
        # Return vertex id if (x,y) is inside a vertex circle
        for vid, (vx, vy, circle_id, label_id) in self.vertices.items():
            dx = x - vx
            dy = y - vy
            if dx*dx + dy*dy <= self.vertex_radius*self.vertex_radius:
                return vid
        return None

    def find_edge(self, x, y):
        # Return edge key if (x,y) is near an edge line (within 5 pixels)
        for (v1, v2), (line_id, entry, entry_window) in self.edges.items():
            x1, y1, _, _ = self.vertices[v1]
            x2, y2, _, _ = self.vertices[v2]
            if self.point_near_line(x, y, x1, y1, x2, y2, 5):
                return (v1, v2)
        return None

    def point_near_line(self, px, py, x1, y1, x2, y2, tol):
        # Check if point (px,py) is within tol pixels of line segment (x1,y1)-(x2,y2)
        # Using distance from point to line segment formula
        from math import sqrt
        line_len_sq = (x2 - x1)**2 + (y2 - y1)**2
        if line_len_sq == 0:
            dist_sq = (px - x1)**2 + (py - y1)**2
            return dist_sq <= tol*tol
        t = max(0, min(1, ((px - x1)*(x2 - x1) + (py - y1)*(y2 - y1)) / line_len_sq))
        proj_x = x1 + t*(x2 - x1)
        proj_y = y1 + t*(y2 - y1)
        dist_sq = (px - proj_x)**2 + (py - proj_y)**2
        return dist_sq <= tol*tol

    def run_boruvka(self):
        # Clear previous MST highlights
        for (v1, v2), (line_id, entry, entry_window) in self.edges.items():
            self.canvas.itemconfig(line_id, fill="black")

        # Build graph adjacency list with weights
        graph = {v: [] for v in self.vertices}
        for (v1, v2), (line_id, entry, entry_window) in self.edges.items():
            try:
                weight = float(entry.get())
            except ValueError:
                messagebox.showerror("Lỗi", f"Trọng số cạnh giữa đỉnh {v1} và {v2} không hợp lệ.")
                return
            graph[v1].append((v2, weight))
            graph[v2].append((v1, weight))

        # Boruvka's algorithm implementation
        parent = {v: v for v in self.vertices}

        def find(u):
            while parent[u] != u:
                parent[u] = parent[parent[u]]
                u = parent[u]
            return u

        def union(u, v):
            ru, rv = find(u), find(v)
            if ru != rv:
                parent[rv] = ru
                return True
            return False
        num_components = len(self.vertices)
        mst_edges = []
        total_weight = 0

        while num_components > 1:
            cheapest = {}
            for u in self.vertices:
                cheapest[u] = None

            for (u, v), (line_id, entry, entry_window) in self.edges.items():
                ru, rv = find(u), find(v)
                if ru != rv:
                    try:
                        w = float(entry.get())
                    except ValueError:
                        messagebox.showerror("Lỗi", f"Trọng số cạnh giữa đỉnh {u} và {v} không hợp lệ.")
                        return
                    if cheapest[ru] is None or cheapest[ru][2] > w:
                        cheapest[ru] = (u, v, w)
                    if cheapest[rv] is None or cheapest[rv][2] > w:
                        cheapest[rv] = (u, v, w)

            for u in self.vertices:
                if cheapest[u] is not None:
                    u1, v1, w1 = cheapest[u]
                    if union(u1, v1):
                        mst_edges.append((u1, v1))
                        total_weight += w1
                        num_components -= 1

        # Highlight MST edges in red
        for (u, v) in mst_edges:
            edge_key = tuple(sorted((u, v)))
            line_id, entry, entry_window = self.edges[edge_key]
            self.canvas.itemconfig(line_id, fill="red")

        # Show total weight
        self.mst_label.config(text=f"Tổng trọng số cây khung nhỏ nhất: {total_weight}")
    def exit_program(self):
        self.root.destroy()

    def restart_program(self):
        self.root.destroy()
        root = tk.Tk()
        app = GraphDrawer(root)
        root.mainloop()

if __name__ == "__main__":
    root = tk.Tk()
    app = GraphDrawer(root)
    root.mainloop()

#include<bits/stdc++.h>
using namespace std;
class Point{
    private:
        double x,y;
    public:
        Point(double x, double y){
            this->x=x;
            this->y=y;
        }
        double getX() const {
            return x;
        }
        double getY() const {
            return y;
        }
        double distance(const Point &p) const {
            return sqrt(pow(x - p.getX(),2) + pow(y - p.getY(), 2));
        }
};
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<Point> points;
        for(int i = 0; i<n; i++){
            double x,y; 
            cin >> x >> y;
            points.push_back(Point(x,y));
        }
        cout << fixed << setprecision(6);
        /*In ma tran:
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout << points[i].distance(points[j]);
                if(j < n-1) cout << " ";
            }
            cout << endl;
        }*/
        //In khoang cach min
        double d_min = 1e9;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                double d = points[i].distance(points[j]);
                if(d < d_min) d_min = d;
            }
        }
        cout << d_min << endl;
    }
    return 0;
}
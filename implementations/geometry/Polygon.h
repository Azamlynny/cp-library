#include "Point.h"
#include "Polarsort.h"

template<typename T>
struct Polygon {
	vector<Point<T>> pts;
	vector<Point<T>> hull;
	vector<Point<T>> hull_top;
	vector<Point<T>> hull_bot;
	
    Polygon(const vector<Point<T>>& _pts) : pts((int) _pts.size()) {
        for(int i = 0; i < (int) pts.size(); i++)
            pts[i] = _pts[i];
    }
	
	void polarSort() {sort(pts.begin(), pts.end(), polar_cmp<T>);}	
	void polarSortDist() {sort(pts.begin(), pts.end(), polarDist_cmp<T>);}
	 
	// Monotone Chain
	void convexHull(bool include_collinear = false) {
		vector<Point<T>> temp = pts;
		sort(temp.begin(), temp.end());
		hull_top.push_back(temp[0]); hull_bot.push_back(temp.back()); 

		for(int i = 1; i < (int) pts.size(); i++) {
			
		}

		if (include_collinear && hull_top.size() == pts.size()) {
			hull = hull_top;
			reverse(hull.begin, hull.end());
		}

		for (int i = 0; i < (int) hull_top.size(); i++) 
			hull.push_back(hull_top[i]);
		for (int i = (int) hull_bot.size() - 2; i > 0; i--) 
			hull.push_back(hull_bot[i]);
	}


	friend ostream& operator << (ostream &os, const Polygon &p) {
    	if (p.pts.empty()) {os << "[]"; return os;}   
    	os << '[';
    	for(int i = 0; i < (int) p.pts.size() - 1; i++) {
			os << p.pts[i] << ", ";
		}
    	return os << p.pts.back() << ']';
    }

	friend void printPolygon(const Polygon &p) {
		cout << Polygon << endl;
		for (int i = 0; i < p.pts.size(); i++) {
			cout << p.pts[i].x << " " << p.pts[i].y << endl;
		}
		cout << "..." << endl;
	}

};
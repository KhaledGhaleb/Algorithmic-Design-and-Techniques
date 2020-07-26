#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
	uint32_t start, end;
};

bool compareByStart(const Segment& a, const Segment& b)
{
	return a.start < b.start;
}

vector<uint32_t> optimal_points(vector<Segment>& segments) {
	vector<uint32_t> points;
	//write your code here
	std::sort(segments.begin(), segments.end(), compareByStart);
	uint32_t left_point = 0, join_point = 0;
	for (size_t i = 0; i < segments.size(); ++i) {

		left_point = segments[i].end;
		join_point = left_point;
		for (int ii = i + 1; ii < segments.size(); ii++) {
			if (left_point >= segments[ii].start) {
				join_point = segments[ii].start;

				if (left_point > segments[ii].end) {
					left_point = segments[ii].end;
				}
				//

				i++;
			}
			else {
				break;
			}
		}


		points.push_back(join_point);
		//points.push_back(segments[i].end);
	}
	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<uint32_t> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
}

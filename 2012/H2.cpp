#include <stdio.h>
#include <map>
using namespace std;
map<pair<int,int>,int>m;
int rabbit(int x, int y) {
    if (x <= 0) {
        return 1;
    } else if (y <= 0) {
        return 2;
    } else {
		map<pair<int,int>,int>::iterator it=m.find(make_pair(x,y));
		if(it!=m.end())return it->second;
        int r=(rabbit(x + 1, y - 2) + rabbit(x - 1, y - 1) + rabbit(x - 3, y + 2)) % 20121224;
		m[make_pair(x,y)]=r;
		return r;
    }
}

int main(void) {
    int xs[10] = { 314, 159, 265, 358, 979, 323, 846, 264, 338, 327, };
    int ys[10] = { 288, 419, 716, 939, 937, 510, 582,  97, 494, 459, };
    int i;
    for (i = 0; i < 10; ++i) {
	m.clear();
        printf("%d\n", rabbit(xs[i], ys[i]));
    }
    return 0;
}

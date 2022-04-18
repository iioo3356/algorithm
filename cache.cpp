// 프로그래머스 캐시
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
	if (cacheSize == 0) return cities.size() * 5;
	vector<string> cache;
	for (int i=0;i<cities.size();i++) {
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(),::tolower);
        int hitIdx = -1;
		for (int j=0;j<cache.size();j++) {
			if (cities[i] == cache[j]) {
				hitIdx = j;
				break;
			}
		}
        if (hitIdx != -1) {
            answer += 1;            
            cache.erase(cache.begin()+hitIdx);
            cache.push_back(cities[i]);
        }
        else {
            answer += 5;
            if (cache.size() >= cacheSize) cache.erase(cache.begin());
            cache.push_back(cities[i]);   
        }
	}
	return answer;
}

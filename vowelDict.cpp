#include <string>
#include <vector>
using namespace std;

char cdict[5] = { 'A','E','I','O','U' };
int answer = 0;

bool dfs(string word, string find) {
	answer++;
	if (!word.compare(find))
		return true;
	if (word.length() == 5)
		return false;

	for (int i = 0; i < 5; i++) {
		if (dfs(word + cdict[i], find))
			return true;
	}
	return false;
}

int solution(string word) {
	dfs("", word);
	return answer - 1;
}

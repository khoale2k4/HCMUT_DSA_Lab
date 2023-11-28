#include <iostream>
#include <stack>

using namespace std;

int baseballScore(string ops) {
	stack<int> st;
	int n = ops.length();
	for (int i = 0; i < n; i++) {
		if (ops[i] < -'9' && ops[i] >= '0') st.push(ops[i] - '0');
		else if (ops[i] == '+') {
			int newdata = st.top();
			st.pop();
			int data = st.top() + newdata;
			st.push(newdata);
			st.push(data);
		}
		else if (ops[i] == 'C') st.pop();
		else if (ops[i] == 'D') {
			int data = st.top() * 2; 
			st.push(data);
		}
	}
	int rs = 0;
	while (!st.empty()) {
		rs += st.top();
		st.pop();
	}
	return rs;
}

int main(){
}
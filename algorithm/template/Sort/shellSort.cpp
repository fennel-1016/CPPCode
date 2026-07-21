#include<iostream>
#include<vector>
using namespace std;
/*虽然希尔排序的演示思路过程是按照每组来进行组内排序的，但是实际会在一次循环中遍历所有的值，而非分组再添加步长
* 
*/

void ShellSort(vector<int>& shell) {
	int n = shell.size();
	for (int gap = n/2; gap > 0; gap/=2) {//缝隙大小，从n/2到1
		for (int i = gap; i < n; i++) {
			int temp = shell[i]; int j;
			for (j = i; j >=gap/*第一排不用读取*/ && shell[j-gap]>temp; j -= gap) {
				shell[j] = shell[j - gap];//后移
				}
			shell[j] = temp;//到了合适的位置
			}
		}
	}
int main() {
	vector<int>a = { 5,1,1,2,0,0};
	ShellSort(a);
	for (int x : a)
		cout << x << ' ';
        
    return 0;
}
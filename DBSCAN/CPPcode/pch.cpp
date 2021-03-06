// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "pch.h"

// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。

static bool isInsec(vector<int >&a, vector<int >&b) {
	
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a.at(i) == b.at(j)) {//远小于O(n2)
				return true;
			}
		}
	}
	return false;
}
void Intersection_of_two_array2d(vector<vector<int>> &array2d)
{
	for (int i = 0; i < array2d.size(); i++) {//先排序
		sort(array2d[i].begin(), array2d[i].end());
	}


	for (int i = 0; i < array2d.size(); i++) {
		if (array2d.at(i).size() == 0)continue;
		for (int j = 0; j < array2d.size(); j++) {
			if (array2d.at(j).size() == 0)continue;
			if (i != j && isInsec(array2d.at(i), array2d.at(j))) {//有交集，合并,j倒进i里面，然后j清空


				for (int m = 0; m < array2d.at(i).size(); m++) {
					for (int n = 0; n < array2d.at(j).size(); n++) {
						if (array2d.at(i).at(m) == array2d.at(j).at(n)) {//相同的标记-1
							array2d.at(j)[n] = -1;
						}
					}
				}

				for (int m = 0; m < array2d.at(j).size(); m++) {//j倒进i
					int temp = array2d.at(j).at(m);
					if (temp != -1) {
						array2d.at(i).push_back(temp);
						array2d.at(j).at(m) = -2;
					}
				}
				sort(array2d.at(i).begin(), array2d.at(i).end());
				array2d.at(j).clear();
				j--;
			}

		}
	}
	for (int i = 0; i < array2d.size(); i++) {//再排序
		sort(array2d[i].begin(), array2d[i].end());
	}
}

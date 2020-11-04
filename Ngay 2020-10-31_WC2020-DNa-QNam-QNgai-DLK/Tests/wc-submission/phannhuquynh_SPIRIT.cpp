#include<bits/stdc++.h>
using namespace std;
int day_la_chu_a_trong_test_mau_bien_a_nha,day_la_chu_b_trong_test_mau_bien_a_nha,day_la_chu_c_trong_test_mau_bien_a_nha;
void solve()
{
	int day_la_chu_d_co_nghia_la_thang_nho_nhat_hien_tai_de_c_nhan_d_nho_hon_a_hien_tai=(day_la_chu_a_trong_test_mau_bien_a_nha/day_la_chu_c_trong_test_mau_bien_a_nha)+1,res=0;
	while(day_la_chu_a_trong_test_mau_bien_a_nha<day_la_chu_b_trong_test_mau_bien_a_nha)
	{
		if(day_la_chu_a_trong_test_mau_bien_a_nha+2==day_la_chu_c_trong_test_mau_bien_a_nha*day_la_chu_d_co_nghia_la_thang_nho_nhat_hien_tai_de_c_nhan_d_nho_hon_a_hien_tai) {
			res++; day_la_chu_a_trong_test_mau_bien_a_nha++;
		}
		else
		if(day_la_chu_a_trong_test_mau_bien_a_nha+2>day_la_chu_c_trong_test_mau_bien_a_nha*day_la_chu_d_co_nghia_la_thang_nho_nhat_hien_tai_de_c_nhan_d_nho_hon_a_hien_tai)
		{
			res++; day_la_chu_a_trong_test_mau_bien_a_nha+=2; day_la_chu_d_co_nghia_la_thang_nho_nhat_hien_tai_de_c_nhan_d_nho_hon_a_hien_tai++;
		}
		else {
			res++; day_la_chu_a_trong_test_mau_bien_a_nha+=2;
		}
	//	cout<<day_la_chu_a_trong_test_mau_bien_a_nha<<" "<<res<<endl;
	}
	cout<<res;
}
int main()
{
//	freopen("SPIRIT.inp","r",stdin);
	cin>>day_la_chu_a_trong_test_mau_bien_a_nha>>day_la_chu_b_trong_test_mau_bien_a_nha>>day_la_chu_c_trong_test_mau_bien_a_nha;
	solve();
	return 0;
}

#include <bits/stdc++.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <io.h> 

using namespace std;

#define ll long long

const string FNAME = "NHANPHAM"; // Ten chuong trinh
const ll N_TEST = 100; // So luong test case can kiem tra

ll mrand(ll, ll); // Sinh so ngau nhien trong doan [a, b]
string i2s(ll); // Convert tu integer -> string

/*
* Method: generateTestCase
* Arguments: 
* 	f_input (string): duong dan toi file *.INP
* Return: void
*/
void generateTestCase(string f_inp) {
	ofstream inp(f_inp.c_str());
	
	ll n = mrand(1, 100), k = mrand(0, 1e18), x;
	inp << n << ' ' << k << '\n';
	while (n--) {
		x = mrand(1, 1e5);
		inp << x << ' ';
	}
	inp.close();
}

int main () {
	srand(time(NULL));
	
	ll score = 0;
	clock_t start, end;
	
	string folder = FNAME + "-test";
	mkdir(folder.c_str());
	
	// Ghi log vao file thi uncomment dong phia duoi
	//freopen((folder + "\\log.txt").c_str(), "w", stdout);
	
	for (int i = 1; i <= N_TEST; i++) {
		string f_inp = folder + "\\"+ FNAME + "-" + i2s(i) +".inp";
		string f_out = folder + "\\"+ FNAME + "-" + i2s(i) +".out";
		string f_ans = folder + "\\"+ FNAME + "-" + i2s(i) +".ans";
		
		generateTestCase(f_inp);
		
		cout << "... " << i << " ..." << endl;
		
		//Run *_ANS.exe voi 2 tham so laf f_inp va f_ans 
		cout << "Generate test case " << i;
		start = clock();
		system((FNAME + "_ANS.exe " + f_inp + " " + f_ans).c_str());
		end = clock();
		cout << " in " << end - start << "ms" << endl;
		
		//Run *.exe voi 2 tham so laf f_inp va f_out
		start = clock();
		system((FNAME + ".exe " + f_inp + " " + f_out).c_str());
		end = clock();
		cout << "Excuted in " << end - start << "ms" << endl;
		
		// So sanh file f_ans voi file f_out
		int code = system(("fc " + f_ans + " " + f_out).c_str());
		if (code != 0) {
			cout << "Wrong answer on test " << i << endl;
		} else if (end - start > 1000) {
			cout << "Time limit exceed on test " << i << endl;
		} else {
			cout << "Correct answer on test " << i << endl;
			score++;
		}
		cout << "-------------------" << endl << endl;
	}
	cout << "Total score: " << score << " / " << N_TEST << endl;
	system("pause");
	return 0;
}

/*
* Method: mrand
* Arguments: 
* 	a (long long): gia tri min
*	b (long long): gia tri max
* Return: (long long): gia tri ngau nhien trong doan [a, b]
*/
ll mrand(ll a, ll b) {
	return a + rand() * RAND_MAX % (b - a + 1);
}


/*
* Method: i2s
* Arguments: 
* 	n (long long): so tu nhien bat ky
* Return: (string): so tu nhien kieu string
*/
string i2s(ll n) {
	string res = "";
	while (n > 0) {
		res = ((char) (n % 10 + 48)) + res;
		n /= 10;
	}
	return res;
}

Sub1:
Gọi dp[i][j] là số thao tác ít nhất để biến đổi dãy từ 1 --> i thành không giảm và a[i] sau khi biến đổi sẽ <= j.
dp[i][j] = max(dp[i][j-1], dp[i-1][j] + abs(a[i]-j)).
Sub2: 
Nhận xét là khi biến đổi dãy {a i } thành không giảm với số thao tác ít nhất, thì sau khi biến đổi thì new[i] = a[j]. (new[i] là số thứ i sau khi biến đổi, a[j] là số trong dãy ban đầu).
Do đó ta có lời giải với độ phức tạp O(N^2).
Giả sử {a i } là chuỗi ban đầu, {b i } gồm các phần tử của {a i } được sắp xếp từ nhỏ nhất đến lớn nhất. Đặt f (i, j) là số lần di chuyển tối thiểu cần thiết để có được chuỗi trong đó các phần tử i đầu tiên không giảm và phần tử thứ i nhiều nhất là b j . Trong trường hợp đó, câu trả lời cho vấn đề sẽ bằng f (n, k), trong đó n là độ dài của {a i } và k là độ dài của {b i }. Chúng tôi sẽ tính f (i, j) bằng cách sử dụng các lần lặp lại sau:
f (1,1) = | a 1 -b 1 |
f (1, j) = min {| a 1 -b j |, f (1, j-1)}, j> 1
f (i, 1) = | a i -b 1 | + f (i-1,1), i> 1
f (i, j) = min {f (i, j-1), f (i-1, j) + | a i -b j |}, i> 1, j> 1. 

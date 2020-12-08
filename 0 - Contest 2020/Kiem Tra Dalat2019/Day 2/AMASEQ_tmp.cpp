void Solve_Min() {
    stack <int> S;
    for (int i=1;i<=n;++i) {
        while (!S.empty() && a[S.top()]>=a[i]) S.pop();
        L_mi[i]=(S.empty() ? 0 : (S.top()));
        L_mi[i]++;
        S.push(i);
    }
    while (!S.empty()) S.pop();
    for (int i=n;i>=1;--i) {
        while (!S.empty() && a[S.top()]>a[i]) S.pop();
        R_mi[i]=(S.empty() ? n+1 : S.top());
        R_mi[i]--;
        S.push(i);
    }
}

void Solve_Max() {
    stack <int> S;
    for (int i=1;i<=n;++i) {
        while (!S.empty() && a[S.top()]<=a[i]) S.pop();
        L_ma[i]=(S.empty() ? 0 : (S.top()));
        L_ma[i]++;
        S.push(i);
    }
    while (!S.empty()) S.pop();
    for (int i=n;i>=1;--i) {
        while (!S.empty() && a[S.top()]<a[i]) S.pop();
        R_ma[i]=(S.empty() ? n+1 : S.top());
        R_ma[i]--;
        S.push(i);
    }
}
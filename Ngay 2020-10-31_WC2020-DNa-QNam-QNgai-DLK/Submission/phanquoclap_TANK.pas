uses crt;
var i,n,l,t:longint;
    m:int64;
    a,f:array[0..100000000] of int64;
begin
    readln(m,n);
    for i:=1 to n do
    begin
        read(a[i]);
        f[i]:=f[i-1]+a[i];
    end;
    for l:=1 to n do
        if f[l]>=m then begin
                   break;
        end;
    for i:=l+1 to n do
    begin
       if f[i]-f[i-l]<=m then
       begin
        inc(l);
        continue;
        end;
    end;
    write(l);
end.


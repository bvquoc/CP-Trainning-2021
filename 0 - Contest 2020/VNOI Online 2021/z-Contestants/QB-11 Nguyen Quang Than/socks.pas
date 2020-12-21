program b3;
const
 fi='socks.inp';
 fo='socks.out';
var
 f,f1:text;
 n,q,i,x:longint;
 u,v,a:array[1..1000]of longint;

begin
 assign(f1,fo); rewrite(f1);
 assign(f,fi); reset(F);
  readln(f,n,q);
  for i;=1 to n do read(f,a[i]);
  for i:=1 to n-1 do read(f,u[i],v[i]);
  lam;
  for i:=1 to q do
   begin
    read(f,x);
    a[x]:=(a[x]+1)mod 2;
    lam;
   end;
 close(F);
 close(F1);
end.
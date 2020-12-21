uses crt;
var f,f1:text;
    a:array[1..5000]of longint;
    b:array[1..5000]of longint;
    c:array[1..5000]of longint;
    i,j,t,min,max,m,n,d,t1,k:longint;

begin
clrscr;
assign(f,'d:\input2.inp');
reset(f);
assign(f1,'d:\output.out');
rewrite(f1);
readln(f,m);
for i:=1 to m do
readln(f,a[i],b[i]);
//////////////////////////////
t:=0;
min:=a[1];
for k:=2 to m do
if a[k]<min then
min:=a[k];
i:=k;
///////////////////////////////
for j:=m downto 1 do
if (b[k]>=a[j]) and (b[k]<=b[j])   then
begin
t:=t+1;
c[t]:=j;
end;



///////////////////////////////
readln(f,n);
for i:=1 to n do
begin
read(f,t1);
for j:=1 to t do
if (t1>=a[c[j]]) and (t1<=b[c[j]]) then
d:=d+1;
end;
////////////////////////////////
k:=0;
for j:=1 to t do
 if (100000>=a[c[j]]) and (100000<=b[c[j]]) then
  begin
   k:=1;
   write(d);
   break;
  end;
  if k=0 then write(-1);
////////////////////////////

close(f);
close(f1);
readln;
end.




uses crt;
var i,j,dau,cuoi,t,n,k,d,s:integer;
a:array[1..50]of integer;
f,f1:text;
begin
clrscr;
assign(f,'d:\permeow.inp');
reset(f);
assign(f1,'d:\permeow.out');
rewrite(f1);
readln(f,n);
while not eof(f) do
begin
for i:=1 to n do
read(f,a[i]);
i:=n-1;
repeat
if a[i]>a[i+1] then
 begin
  k:=n;
 repeat
  if a[i]>a[k] then
   begin
    t:=a[i];
    a[i]:=a[k];
    a[k]:=t;
{lat doan con }
    dau:=i+1;
    cuoi:=n;
    repeat
     t:=a[dau];
     a[dau]:=a[cuoi];
     a[cuoi]:=t;
     dau:=dau+1;
     cuoi:=cuoi-1;
    until dau>=cuoi ;
    d:=d+1;

    i:=n-1;
   break;
  end
else
  k:=k-1;
 until k=i;
  end
  else
  i:=i-1;
until i=0;
s:=s+d;
d:=0;
for i:=1 to n do
a[i]:=0;
end;
if s=0 then write(0) else
write((1000000000+7) mod s);
close(f);
close(f1);
readln;
end.



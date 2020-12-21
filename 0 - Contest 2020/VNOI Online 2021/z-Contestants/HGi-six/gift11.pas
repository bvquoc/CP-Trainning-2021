uses crt;
var i,j,dau,cuoi,t,n,k,d,gift,t1,t2,chan,le,tong,num,code:integer;
f,f1:text;
c,so:string;
a:array[1..50]of longint;
begin
clrscr;
assign(f,'d:\gift11.inp');
reset(f);
assign(f1,'d:\gift11.out');
rewrite(f1);
readln(f,gift);
for t1:=1 to gift do
begin
so:='';
d:=0;
chan:=0;
le:=0;
readln(f,n);
for i:=1 to n do
read(f,a[i]);
for i:=1 to n-1 do
 for j:=i+1 to n do
  if a[i]>a[j] then
   begin
    t:=a[i];
    a[i]:=a[j];
    a[j]:=t;
   end;
for i:=1 to n do
 begin
  str(a[i],c);
  so:=so+c;
 end;
for i:=1 to length(so) do
if i mod 2=0 then
  begin
   val(so[i],num,code);
   chan:=chan+num;
  end
else
 begin
  val(so[i],num,code);
  le:=le+num;
 end;
 t:=1;
 for i:=2 to n do
 if a[1]=a[i] then
 t:=t+1;
 t2:=0;

 if ((chan-le) mod 11=0) and (t=n) then
   begin
    d:=t;
    t2:=2;
   end;


 if t2=0 then
begin
if (chan-le) mod 11=0 then
 d:=d+1;
i:=n-1;
repeat
if a[i]<a[i+1] then
 begin
  k:=n;
 repeat
  if a[i]<a[k] then
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
    so:='';
    chan:=0;
    le:=0;

    for j:=1 to n do
    begin
     str(a[j],c);
     so:=so+c;
    end;
   for j:=1 to length(so) do
   if j mod 2=0 then
    begin
     val(so[j],num,code);
     chan:=chan+num;
    end
   else
    begin
     val(so[j],num,code);
     le:=le+num
    end;

   if (chan-le) mod 11=0 then
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
end;
writeln(d mod 998244353);
end;
close(f);
close(f1);

readln;
end.



program ct;
const fi='coolmac.inp';
      fo='coolmac.out';
var f:text;
    n,i,x,m,min,y,j,nga,kq:longint;
    a,b,c:array[1..400000]of longint;


procedure sort(l,r: longint);
begin
i:=l; j:=r;
x:=a[(l+r) div 2];
repeat
while a[i]<x do inc(i);
while x<a[j] do dec(j);
if not(i>j) then
begin
y:=a[i]; a[i]:=a[j]; a[j]:=y;
y:=b[i]; b[i]:=b[j]; b[j]:=y;
inc(i); j:=j-1;
end;
until i>j;
if l<j then sort(l,j);
if i<r then sort(i,r);
end;



function sosanh(u,v:longint):longint;
begin
if u>v then u:=v;
sosanh:=u;
end;


procedure xl(u,v,vt,l,so:longint);
begin
if (u>l)or(v<l) then exit else
if (u=l)and(v=l) then c[vt]:=sosanh(c[vt],so) else
begin
xl(u,(u+v) div 2,vt*2,l,so);
xl((u+v) div 2+1,v,vt*2+1,l,so);
c[vt]:=sosanh(c[vt*2],c[vt*2+1]);
end;
end;



procedure pt(u,v,vt,l,r:longint);
begin
if (u>r)or(l>v) then exit else
if (l<=u)and(v<=r) then nga:=sosanh(nga,c[vt]) else
begin
pt(u,(u+v) div 2,vt*2,l,r);
pt((u+v) div 2+1,v,vt*2+1,l,r);
end;
end;

begin
assign(f,fi);reset(f);
readln(f,m);
for i:=1 to m do readln(F,a[i],b[i]);
sort(1,m);  min:=high(longint);
readln(f,n);
for i:=1 to n do
begin
read(f,x);
if min>x then min:=x;
end;
for i:=1 to 400000 do c[i]:=high(longint);
close(f);
assign(f,fo);rewrite(F);
kq:=high(longint);
for i:=1 to m do
begin
if (a[i]<=min)and(min<=b[i]) then nga:=1 else
begin
nga:=high(longint);
pt(1,100000,1,a[i],100000);
if nga<>high(longint) then nga:=nga+1;
end;
xl(1,100000,1,b[i],nga);
if b[i]=100000 then
if kq>nga then kq:=nga;
end;
if kq=high(longint) then  writeln(f,-1) else writeln(f,kq);
close(f);
end.




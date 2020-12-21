const fi='dhaka.inp';
      fo='dhaka.out';
var n,m,i,j,k,ll,x,y:longint;
    a,b:array[0..100000,0..5]of int64;
    u,v,c,d,g:array[0..200000]of int64;
    w:array[0..1000000]of int64;
    f:text;

procedure sort(l,r:longint);
begin
i:=l; j:=r;
x:=u[(l+r) div 2];
repeat
while u[i]<x do inc(i);
while x<u[j] do dec(j);
if not(i>j) then
begin
y:=u[i]; u[i]:=u[j]; u[j]:=y;
y:=v[i]; v[i]:=v[j]; v[j]:=y;
y:=c[i]; c[i]:=c[j]; c[j]:=y;
inc(i); j:=j-1;
end;
until i>j;
if l<j then sort(l,j);
if i<r then sort(i,r);
end;



procedure xl(so:longint);
var l,r,dem:longint;
begin
for l:=d[so-1]+1 to d[so] do
begin
dem:=b[so,0];
for r:=1 to 5 do
if (b[so,r]=0)and(a[v[l],r]=1) then inc(dem);
if dem>ll then dem:=ll;
if (b[v[l],0]<dem)or((b[v[l],0]=dem)and(g[v[l]]>g[so]+c[l])) then
begin
b[v[l],0]:=dem;
g[v[l]]:=g[so]+c[l];
for r:=1 to 5 do b[v[l],r]:=b[so,r]+a[v[l],r];
y:=y+1; w[y]:=v[l];
end;
end;
x:=x+1;
if x<=y then xl(w[x]);
end;


begin
assign(f,fi);reset(f);
readln(f,n,m,k,ll);
for i:=1 to n do
begin
read(f,x);
for j:=1 to x do begin read(f,y); a[i,y]:=1; end;
end;
for i:=1 to m do
begin
readln(f,u[i],v[i],c[i]);
u[i+m]:=v[i];
v[i+m]:=u[i];
c[i+m]:=c[i];
inc(d[u[i]]);
inc(d[v[i]]);
end;
for i:=1 to n do begin d[i]:=d[i]+d[i-1]; g[i]:=high(longint); end;
sort(1,m+m);
close(f);
assign(f,fo);rewrite(f);
g[1]:=0;
x:=0; y:=0;
xl(1);
if b[n,0]>=ll then writeln(f,g[n]) else writeln(f,-1);
close(f);
end.

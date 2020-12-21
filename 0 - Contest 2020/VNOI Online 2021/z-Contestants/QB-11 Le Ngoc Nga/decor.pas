program ct;
const fi='decor.inp';
      fo='decor.out';
var f:text;
    n,m,k,i,j,u,v,t,max,dau,cuoi:longint;
    a,b,c:array[1..500000]of longint;
    s:array[1..500000]of char;

procedure xl(l,r:longint);
var z,x,y,vt:longint;
begin
x:=l; y:=r;
while a[l]<>l do l:=a[l];
while a[r]<>r do r:=a[r];
if l<>r then b[l]:=b[l]+b[r];
z:=l;
while x<>a[x] do begin vt:=x; x:=a[x]; a[vt]:=z; end;
a[x]:=z;
while y<>a[y] do begin vt:=y; y:=a[y]; a[vt]:=z; end;
a[y]:=z;
end;


function min(x,y:longint):longint;
begin
if x>y then x:=y;
min:=x;
end;


begin
assign(f,fi);reset(f);
readln(f,n,m,k);

for i:=1 to n do
begin
a[i]:=i;
read(f,s[i]);
if s[i]='1' then b[i]:=1;
end;

for i:=1 to m do
begin
readln(F,u,v);
xl(u,v);
end;
close(f);
assign(f,fo);rewrite(f);
t:=0; i:=1; j:=0; max:=0;
u:=0; v:=0;
while (j<>n) do
begin
u:=min(c[a[j+1]]+1,b[a[j+1]]);
v:=min(c[a[j+1]],b[a[j+1]]);
if (j+1-i+1)-(t-v+u)<=k then
begin
t:=t-v+u;
j:=j+1;
inc(c[a[j]]);
if max<j-i+1 then begin max:=j-i+1; dau:=i; cuoi:=j; end;
end else
begin
u:=min(c[a[i]],b[a[i]]);
v:=min(c[a[i]]-1,b[a[i]]);
dec(c[a[i]]);
i:=i+1;
t:=t-u+v;
end;
end;
if max=0 then writeln(F,-1) else writeln(f,dau,' ',cuoi);
close(F);
end.


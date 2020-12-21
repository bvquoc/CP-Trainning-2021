program bai1;
const fi='coolmac.inp';
      fo='coolmac.out';
var f:text;
    i,j,m,n,min,d,l,dem:longint;
    a,b,c,e,tr:array[1..100000] of longint;
    ct:array[1..100000] of boolean;
procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if not(i>j) then
      begin
        y:=a[i]; a[i]:=a[j]; a[j]:=y;
        y:=b[i]; b[i]:=b[j]; b[j]:=y;
        inc(i);
        dec(j);
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
begin
  assign(f,fi);
  reset(f);
  readln(f,n);
  for i:=1 to n do
    begin
      readln(f,a[i],b[i]);
      c[i]:=1;
      tr[i]:=0;
    end;
  sort(1,n);
  readln(f,m);
  for i:=1 to m do read(f,e[i]);
  close(f);
  assign(f,fo);
  rewrite(f);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (a[j]<=b[i]) and (b[j]>b[i]) then if c[j]<c[i]+1 then begin c[j]:=c[i]+1; tr[j]:=i; end;
  min:=1000000;
  for i:=n downto 1 do
    if b[i]=100000 then
      begin
        for j:=1 to m do ct[j]:=false;
        l:=i;
        d:=0;
        dem:=0;
        repeat
          inc(d);
          for j:=1 to m do
            if (e[j]>=a[l]) and (e[j]<=b[l]) and (ct[j]=false) then begin ct[j]:=true; inc(dem); end;
          l:=tr[l];
        until (l=0) or (dem=m);
        if (min>d) and (dem=m) then min:=d;
      end;
  if min<>1000000 then writeln(f,min) else writeln(f,'-1');
  close(f);
end.

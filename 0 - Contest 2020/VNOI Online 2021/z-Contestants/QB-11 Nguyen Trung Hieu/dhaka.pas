program bai1;
const fi='dhaka.inp';
      fo='dhaka.out';
var f:text;
    n,m,k,l,i,j,dem,x,y,z:longint;
    a,p:array[1..100000] of longint;
    o:array[1..100000] of int64;
    e:array[1..10000,1..10000] of int64;
    b:array[1..5,1..5] of longint;
    c:array[1..5] of longint;
    ct:array[1..100000] of boolean;
function min:longint;
var i:longint;
    j:int64;
begin
  min:=0;
  j:=1000000000000;
  for i:=1 to n do
    if (j>o[i]) and (ct[i]=false) then begin j:=o[i]; min:=i; end;
end;
procedure distral;
var i,j:longint;
begin
  for i:=1 to n do o[i]:=e[1,i];
  o[1]:=0;
  repeat
    i:=min;
    if i=0 then break;
    ct[i]:=true;
    for j:=1 to n do
      if (o[j]>o[i]+e[i,j]) and (ct[j]=false) then o[j]:=o[i]+e[i,j];
  until false;
end;
procedure duyetrong;
var i,j,dau,cuoi,dem:longint;
begin
  p[1]:=1;
  dau:=0;
  cuoi:=1;
  for i:=1 to a[1] do
    inc(c[b[1,i]]);
  dem:=0;
  for i:=1 to 5 do
    if c[i]>0 then inc(dem);
  while dau<cuoi do
    begin
      inc(dau);
      i:=p[dau];
      ct[i]:=true;
      for j:=1 to n do
        if (ct[j]=false) and (e[i,j]<>0) then
          begin
            inc(cuoi);
            p[cuoi]:=j;
          end;
    end;
end;
begin
  assign(f,fi);
  reset(f);
  readln(f,n,m,k,l);
  for i:=1 to n do
    begin
      read(f,a[i]);
      for j:=1 to a[i] do begin read(f,b[i,j]); inc(c[b[i,j]]); end;
      readln(f);
    end;
  for i:=1 to n do
    begin
      ct[i]:=false;
      for j:=1 to m do e[i,j]:=1000000000000;
    end;
  for i:=1 to m do
    begin
      readln(f,x,y,z);
      e[x,y]:=z;
      e[y,x]:=z;
    end;
  close(f);
  assign(f,fo);
  rewrite(f);
  if l=0 then
    begin
      distral;
      writeln(f,o[n]);
    end else
      begin
        dem:=0;
        for i:=1 to n do ct[i]:=false;
        for i:=1 to 5 do if c[i]>0 then inc(dem);
        if dem<l then writeln(f,'-1');
      end;
  close(f);
end.
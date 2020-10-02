uses crt;
var n,m,i,j,u,v:integer;
    d,trace:array[1..100]of integer;
    c:array[1..100,1..100]of integer;
    free:array [1..100] of boolean;
    f:text;
{---------------}
procedure nhap;
  begin
  assign(f,'DULICH.INP');
  reset(f);
  readln(f,n,m);
  for u:=1 to n do
    for v:=1 to n do
      if u=v then c[u,v]:=0
      else c[u,v]:=maxint;
  for i:=1 to m do
    readln(f,u,v,c[u,v]);
  close(f);
  end;
{-------------}
procedure khoitao;
  begin
  for i:=1 to n do
    free[i]:=true;
  for i:=1 to n do
    d[i]:=maxint;
  for i:=1 to n do
    trace[i]:=0;
  d[1]:=0;
  end;
{---------------}
procedure dulichve;
var min,n1:integer;
  begin
  n1:=n;
  for i:=1 to n do
    free[i]:=true;
  while n<>0 do
    begin
    free[n]:=false;
    n:=trace[n];
    end;
  n:=n1;
  for i:=1 to n-1 do
    d[i]:=maxint;
  free[1]:=true;
  free[n1]:=true;
  repeat
    min:=maxint;
    u:=0;
    for i:=1 to n do
      if free[i] and (d[i]<min) then
        begin
        u:=i;
        min:=d[i];
        end;
    if (u=0) or (u=1) then break;
    free[u]:=false;
    for v:=1 to n do
      if free[v] and (d[v]>d[u]+c[u,v]) then
        begin
        d[v]:=d[u]+c[u,v];

        end;
  until false;
  end;
{------------}
procedure dulich;
var min:integer;
  begin
  repeat
    u:=0;
    min:=maxint;
    for i:=1 to n do
      if free[i] and (d[i]<min) then
        begin
        min:=d[i];
        u:=i;
        end;
    if (u=0) then break;
    if (u=n) then
      begin
      dulichve;
      break;
      end;
    free[u]:=false;
    for v:=1 to n do
      if free[v] and (d[v]>d[u]+c[u,v]) then
        begin
        trace[v]:=u;
        d[v]:=d[u]+c[u,v];
        end;
  until false;
  end;
{--------------}
procedure xuat;
  begin
  assign(f,'DULICH.OUT');
  rewrite(f);
  if (d[n]<>maxint) and (d[1]<>maxint) then write(f,d[1])
  else write(f,0);
  close(f);
  end;
{--------------}
begin
 nhap;
 khoitao;
 dulich;
 xuat;
end.

uses crt;
var n,t,i,j,u,v:integer;
    ex:array[1..100,1..100]of boolean;
    free:array[1..100]of boolean;
    d:array[1..100,1..100]of integer;
    trace:array[1..100]of integer;
    u1,v1:array[1..100]of integer;
    f:text;
{------------}
 procedure nhap;
  begin
  assign(f,'LAMPS.INP');
  reset(f);
  readln(f,n,t);
  for i:=1 to n - 1 do
    begin
    readln(f,u,v);
    ex[u,v]:=true;
    end;
  for i:=1 to t do
    begin
    readln(f,u1[i],v1[i]);
    end;
  for i:=1 to t do
    begin
    for j:=1 to n do
      read(f,d[i,j]);
    readln(f);
    end;
  close(f);
  end;
{------------}
procedure khoitao(t:integer);
var i:integer;
  begin
  for i:=1 to n do
    free[i]:=true;
  ex[u1[t],v1[t]]:=true;
  end;
{-------------}
{procedure dq(i:integer);
var j:integer;
  begin
  d[i]:=1;
  u:=i;
  free[u]:=false;
  for v:=1 to n do
    if ex[u,v] and free[v] then
      if d[v]=0 then
        begin
        d[v]:=1;
        trace[v]:=u;
        end;
      else
        d[v]:=0;
  for j:=1 to n do
    if (d[j]=1) and (trace[j]<>0) and (free[j]) then
      dq(j)
    else exit;
  end;  }
{-----------}
begin
 nhap;

 readln
end.

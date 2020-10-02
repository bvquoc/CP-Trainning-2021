type mang=array[1..100]of longint;
var w,d,p:mang;
    n,m,i:integer;
    sum:longint;
    f:text;
{-------------}
procedure nhap;
  begin
  assign(f,'TALENT.INP');
  reset(f);
  readln(f,n,m);
  for i:=1 to n do
    read(f,d[i]);
  readln(f);
  for i:=1 to n do
    read(f,w[i]);
  readln(f);
  for i:=1 to m do
    readln(f,p[i]);
  close(f);
  end;
{-----------}
procedure xuli;
var j:integer;
  begin
  for i:=1 to m do
    begin
    sum:=0;
    for j:=1 to n do
      sum:=sum+w[j]*abs(d[j]-p[i]);
    writeln(f,sum);
    end;
  end;
{------------}
begin
 nhap;
 assign(f,'TALENT.OUT');
 rewrite(f);
 xuli;
 close(f);
end.
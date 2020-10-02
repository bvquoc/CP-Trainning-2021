uses crt;
type mang=array[1..10000]of longint;
     mang1=array[1..10000]of boolean;
var a,b:mang;
    n:longint;
    i,j,dem:integer;
    f:text;
    freeb:mang1;
{--------------}
procedure nhap;
  begin
  assign(f,'IQ.INP');
  reset(f);
  readln(f,n);
  for i:=1 to n do
    read(f,b[i]);
  for i:=1 to n do
    read(f,a[i]);
  close(f);
  end;
{-------------}
procedure khoitao;
var z:longint;
  begin
  for i:=1 to n do
    begin
    freeb[i]:=true;
    end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]<a[j] then
        begin
        z:=a[i];
        a[i]:=a[j];
        a[j]:=z;
        end;
  end;
{---------------}
procedure xuli;
var k:integer;
    max:longint;
  begin
  dem:=0;
  for i:=1 to n do
    begin
    k:=0;
    max:=-1000000000;
    for j:= 1 to n do
      if (max<b[j]) and freeb[j] and (b[j]<a[i])then
        begin
        max:=b[j];
        k:=j;
        end;
    if k=0 then continue;
    freeb[k]:=false;
    dem:=dem+1;
    end;
  end;
{------------}
procedure xuat;
  begin
  assign(f,'IQ.OUT');
  rewrite(f);
  write(f,dem);
  close(f);
  end;
{-----------}
begin
 nhap;
 khoitao;
 xuli;
 xuat;
end.


uses crt;
type mang=array[1..1000,1..1000]of integer;
     mang2=array[1..1000,1..1000]of boolean;
     mang3=array[1..1000]of integer;
var i,j,n,r,k,s:integer;
    a:mang;
    b:mang3;
    free:mang2;
    f:text;
{------------}
procedure nhap;
  begin
  assign(f,'BONUS.INP');
  reset(f);
  readln(f,n,r,k);
  for i:=1 to n do
    begin
    for j:=1 to n do
      begin
      free[i,j]:=true;
      read(f,a[i,j]);
      end;
    readln(f);
    end;
  for i:=1 to k do
    readln(f,b[i]);
  close(f);
  end;
{-------------}
procedure xuli;
var l:integer;
  begin
  s:=0;
  for l:=1 to k do
    begin
    for i:=b[l] to b[l]+r-1 do
      for j:=b[l]to b[l]+r-1 do
        if free[i,j] then
          begin
          s:=s+a[i,j];
          free[i,j]:=false;
          end;
    end;
  end;
{------------}
procedure xuat;
  begin
  assign(f,'BONUS.OUT');
  rewrite(f);
  write(f,s);
  close(f);
  end;
{-------------}
begin
 nhap;
 xuli;
 xuat;
end.
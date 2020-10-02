uses crt;
type mang=array[1..100]of integer;
var n,k,i:integer;
    a:mang;
    f:text;
{-------------}
procedure nhap;
  begin
  assign(f,'TEAM.INP');
  reset(f);
  readln(f,n,k);
  for i:=1 to n do
    read(f,a[i]);
  close(f);
  end;
{----------------}
procedure xuli;
var i,l:integer;
  begin
  i:=0;
  l:=k;
  while k>0 do
    begin
    if i<> n then
      begin
      i:=i+1;
      k:=k-a[i];
      end
    else
      begin
      i:=1;
      k:=k-a[i];
      end;
    end;
  if k <> 0 then k:=k+a[i];
  end;
{-------------}
procedure xuat;
  begin
  assign(f,'TEAM.OUT');
  rewrite(f);
  write(f,k);
  close(f);
  end;
{-------------}
begin
 nhap;
 xuli;
 xuat;
end.

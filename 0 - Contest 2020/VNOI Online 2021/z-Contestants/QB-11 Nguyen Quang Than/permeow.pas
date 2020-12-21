program ct;
const fi='permeow.inp';
      fo='permeow.out';
var f:text;
    a,b,c:array[1..200000] of longint;
    i,d,dem,n:longint;
procedure hv;
var i,j,k,l,tg:longint;
begin
  i:=n-1;
  while a[i]>a[i+1] do dec(i);
  j:=n;
  while a[i]>a[j] do dec(j);
  tg:=a[i]; a[i]:=a[j]; a[j]:=tg;
  for k:=i+1 to n-1 do
    for l:=k+1 to n do
      if a[k]>a[l] then
        begin
          tg:=a[k];
          a[k]:=a[l];
          a[l]:=tg;
        end;
end;
function sx:longint;
var i,j,tg:longint;
begin
  sx:=0;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if c[i]>c[j] then
        begin
          inc(sx);
          tg:=c[i];
          c[i]:=c[j];
          c[j]:=tg;
        end;
end;
begin
  assign(f,fi); reset(f);
  readln(f,n);
  for i:=1 to n do read(f,a[i]);
  d:=0;
  for i:=1 to n do
    begin
      read(f,b[i]);
      if a[i]=b[i] then inc(d);
    end;
  close(f);
  assign(f,fo); rewrite(f);
  if d=n then
    begin
      dem:=0;
      for i:=1 to n do c[i]:=a[i];
      inc(dem,sx);
      writeln(f,dem);
    end else
      begin
        dem:=0;
        for i:=1 to n do c[i]:=a[i]; inc(dem,sx);
        d:=0;
        repeat
          d:=0;
          hv;
          for i:=1 to n do c[i]:=a[i];
          inc(dem,sx);
          for i:=1 to n do
            if a[i]=b[i] then inc(d) else break;
        until d=n;
        writeln(f,dem);
      end;
  close(f);
end.

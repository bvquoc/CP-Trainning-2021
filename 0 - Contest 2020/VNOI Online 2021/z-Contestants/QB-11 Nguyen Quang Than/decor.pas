program b1;
const
 fi='decor.inp';
 fo='decor.out';
var
 f:text;
 n,i,m,k,u,v,dem,vt,max:longint;
  x:char;
  a:array[0..100000]of longint;
begin              max:=-2147483647;
 assign(f,fi); reset(F);
  readln(f,n,m,k);
  for i:=1 to n do
   begin
    read(f,x);
    if x='1' then a[i]:=1+a[i-1] else a[i]:=0;
   end;
  for i:=1 to m do readln(f,u,v);
 close(f);
 assign(f,fo); rewrite(F);
   for i:=1 to n do
    begin
     if a[i]=0 then inc(dem);
    if a[i]>max then
    begin
     vt:=i;
     max:=a[i];
    end;
    end;
   if k=0 then write(f,vt-a[vt]+1,' ',vt) else
    begin
     if k>=dem then write(f,'1 ',n);
    end;
 close(F);
 end.


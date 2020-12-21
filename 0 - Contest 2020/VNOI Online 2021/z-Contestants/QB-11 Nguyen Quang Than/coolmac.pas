program  b1;
const
 fi='coolman.inp';
 fo='coolman.out';
var
 f:text;
 n,m,j,k,i,vt,min,x:longint;
 l,r:array[0..100005]of longint;
procedure sort(l1,r1: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l1;
         j:=r1;
         x:=r[(l1+r1) div 2];
         repeat
           while r[i]<x do
            inc(i);
           while x<r[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=r[i];
                r[i]:=r[j];
                r[j]:=y;
                y:=l[i];
                l[i]:=l[j];
                l[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l1<j then
           sort(l1,j);
         if i<r1 then
           sort(i,r1);
      end;
procedure xoa(x:longint);
begin

 for k:=x to m-1 do
  begin
   l[k]:=l[k+1];
   r[k]:=r[k+1];
  end;
 l[m]:=0;
 r[m]:=0;
  dec(m);
end;
begin
 min:=214483647;
 assign(f,fi); reset(F);
 readln(f,m);
 for i:=1 to m do
  readln(f,l[i],r[i]);
 readln(f,n);
 for i:=1 to n do
  begin
   read(f,x);
   if x<min then min:=x;
  end;
 close(F);
 assign(f,fo); rewrite(f);
  sort(1,m);
  i:=1;
  while i<m do
   begin
    vt:=i;
    inc(i);
    while r[i]=r[vt] do
     if l[i]>l[vt] then xoa(i) else
     xoa(vt);
   end;
  if r[m]<100000 then write(f,-1) else
   begin
   for i:=m-1 downto 0 do if r[i]<l[i+1] then break;
   if min<l[i+1] then write(f,-1) else for j:=m downto 1 do if l[j]<=min then
    begin
     write(f,m-j+1);
     break;
    end;
   end;

 close(F);
end.

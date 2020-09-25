{$M 65000,0,655360}

const
   tfi='in.09';
   tfo='Bridges.ou9t';

type
   mang1=array[1..10001] of integer;
   mang2=array[1..10001] of real;
   mang3=array[1..20001] of integer;

var
   fi, fo: text;
   N,K: integer;
   vp,vc: integer;
   cs,d,c,L: ^mang1;
   tro: mang1;
   ke: mang3;
   phai: ^mang1;
   Ts: ^mang2;

procedure cp;
begin
   new(d);
   new(c);
   new(L);
   new(Ts);
   new(phai);
end;

procedure Nhap;
var i: integer;
begin
   assign(fi,tfi); reset(fi);
   readln(fi,N,K,vp,vc);
   for i:=1 to N do readln(fi,d^[i],c^[i],L^[i]);
   close(fi);
end;

procedure Chbi;
var i,v,u: integer;
begin
   for i:=1 to N do tro[i]:=0;
   for i:=1 to n-1 do
      begin
         inc(tro[d^[i]]);
         inc(tro[c^[i]]);
      end;
   v:=0;
   for i:=1 to n do
      begin
         u:=tro[i];
         tro[i]:=v+1;
         v:=v+u;
      end;
   tro[n+1]:=v+1;
   for i:=1 to n-1 do
      begin
         u:=d^[i];
         v:=c^[i];
         ke[tro[u]]:=i;
         ke[tro[v]]:=i;
         inc(tro[u]);
         inc(tro[v]);
      end;
   for i:=n downto 2 do tro[i]:=tro[i-1];
   tro[1]:=1;
end;

function Gtri(u,Num: integer): real;
var p: real;
begin
   p:=1.0*Num*(N-Num);
   if vc>=vp then p:= p*L^[u]
   else           p:=-p*L^[u];
   Gtri:=p;
end;

procedure Dfs(u: integer);
var i,r,v: integer;
begin
   Phai^[u]:=1;
   for i:=tro[u] to tro[u+1]-1 do
      begin
         r:=ke[i];
         if d^[r]=u then v:=c^[r] else v:=d^[r];
         if phai^[v]=0 then
            begin
               Dfs(v);
               Ts^[r]:=Gtri(r,Phai^[v]);
               Phai^[u]:=Phai^[u]+Phai^[v];
            end;
      end;
end;

procedure Doi(var u,v: integer);
var w: integer;
begin
   w:=u;
   u:=v;
   v:=w;
end;

procedure Sort(u,v: integer);
var r: real;
    i,j: integer;
begin
   r:=Ts^[cs^[(u+v) div 2]];
   i:=u;
   j:=v;
   repeat
      while Ts^[cs^[i]]>r do inc(i);
      while Ts^[cs^[j]]<r do dec(j);
      if i<=j then
         begin
            Doi(cs^[i],cs^[j]);
            inc(i);
            dec(j);
         end;
   until i>j;
   if u<j then Sort(u,j);
   if i<v then Sort(i,v);
end;

procedure Tim;
var i: integer;
begin
   for i:=1 to n do phai^[i]:=0;
   Dfs(1);
   cs:=d;
   for i:=1 to n do cs^[i]:=i;
   assign(fo,tfo); rewrite(fo);
   for i:=1 to n-1 do writeln(fo,ts^[i]:0:0);
   close(fo);
   Sort(1,N-1);
end;

procedure Xuat;
var i: integer;
begin
   assign(fo,tfo); rewrite(fo);
   for i:=1 to K do writeln(fo,cs^[i]);
   close(fo);
end;

BEGIN
   cp;
   Nhap;
   Chbi;
   Tim;
  { Xuat;}
END.
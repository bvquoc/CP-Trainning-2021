const

     fi         =       'in.02';
     fo         =       'build.out';
     maxN       =       101;
     inf        =       1000000000;

var

     f          :       text;
     n,m,kq     :       longint;
     x,y,z,k    :       longint;
     c,d,tr     :       array[0..maxN]of longint;
     a,b,cur     :       array[1..maxN,1..maxN]of integer;

procedure nhapdl;
var

     i,u,v,w    :       longint;

begin

     assign(f,fi);
     reset(f);

     readln(f,n);
     fillchar(a,sizeof(a),0);
     readln(f,x,y,z,k);
     while not seekeof(f) do
       begin
         readln(f,u,v,w);
         a[u,v]:=w;
         a[v,u]:=w;
       end;

     close(f);

end;

procedure chuanbi(s:longint);
var

     i          :       longint;

begin

     for i:=0 to n do c[i]:=inf;
     fillchar(tr,sizeof(tr),0);
     fillchar(d,sizeof(d),0);
     c[s]:=0;

end;

procedure pop(var u:longint);
var

     v          :       longint;

begin

     u:=0;
     for v:=1 to n do
       if c[u]>c[v] then
         if d[v]=0 then u:=v;

end;

procedure truyvet(s,t:longint);
var

     u,v        :       longint;

begin

     if s=t then exit;
     if tr[t]=0 then
       begin
         for u:=1 to n do
           for v:=1 to n do b[u,v]:=1;
         exit;
       end;
     u:=t;
     repeat
       v:=tr[u];
       b[u,v]:=1;
       u:=v;
     until u=s;

end;

procedure ijk(s,t:longint);
var

     u,v        :       longint;

begin

     chuanbi(s);
     repeat
       pop(u);
       if (u=t)or(u=0) then break;
       d[u]:=1;
       for v:=1 to n do
         if a[u,v]>0 then
           if c[v]>c[u]+a[u,v] then
             begin
               c[v]:=c[u]+a[u,v];
               tr[v]:=u;
             end;
     until false;
     truyvet(s,t);

end;

procedure tinh(var p:longint);
var

     i,j        :       longint;

begin

     p:=0;
     for i:=1 to n do
       for j:=1 to n do
         if b[i,j]=1 then
           begin
             b[i,j]:=2;
             b[j,i]:=2;
             p:=p+a[i,j];
           end;

end;

procedure xuli;
var

     i,min      :       longint;

begin

     kq:=inf;
     for i:=1 to n do
       begin
         fillchar(b,sizeof(b),0);
         ijk(x,i);
         ijk(y,i);
         ijk(z,i);
         ijk(k,i);
         tinh(min);
         if kq>min then
           begin
             kq:=min;
             cur :=b;
           end;
       end;

end;

procedure ghikq;
var

     i,j        :       longint;

begin

     assign(f,fo);
     rewrite(f);

     writeln(f,kq);
     for i:=1 to n do
       for j:=1 to n do
         if cur [i,j]=2 then
           begin
             writeln(f,i,#32,j);
             cur [i,j]:=0; cur [j,i]:=0;
           end;

     close(f);

end;

begin

     nhapdl;
     xuli;
     ghikq;

end.
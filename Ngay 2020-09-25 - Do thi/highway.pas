const

     fi         =       'highway.inp';
     fo         =       'highway.out';
     maxN       =       1001;
     sum        =       1000000000;

var

     f          :       text;
     n,m,sl     :       longint;
     x,y        :       array[1..maxN]of longint;
     d,t        :       array[0..maxN]of integer;
     c          :       array[0..maxN]of extended;
     luu        :       array[1..2,1..maxN]of integer;
     a          :       array[1..maxN,1..maxN]of extended;

function  kc(i,j:longint):extended;
begin

     kc:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));

end;

procedure capnhat(i:longint);
var

     j          :       longint;

begin

     for j:=1 to i-1 do
       begin
         a[i,j]:=kc(i,j);
         a[j,i]:=a[i,j];
       end;

end;

procedure nhapdl;
var

     i,u,v      :       longint;

begin

     assign(f,fi);
     reset(f);

     readln(f,n);
     for i:=1 to n do
       begin
         readln(f,x[i],y[i]);
         capnhat(i);
       end;
     readln(f,m);
     for i:=1 to m do
       begin
         readln(f,u,v);
         a[u,v]:=0;
         a[v,u]:=0;
       end;

     close(f);

end;

procedure chuanbi;
var

     i          :       longint;

begin

     for i:=0 to n do c[i]:=sum;
     fillchar(d,sizeof(d),0);
     c[1]:=0;

end;

procedure pop(var u:longint);
var

     v          :       longint;

begin

     u:=0;
     for v:=1 to n do
       if c[v]<c[u] then
         if d[v]=0 then u:=v;

end;

procedure xuli;
var

     u,v        :       longint;

begin

     repeat
       pop(u);
       if u=0 then break;
       d[u]:=1;
       for v:=1 to n do
         if (c[v]>a[u,v])and(d[v]=0) then
           begin
             c[v]:=a[u,v];
             t[v]:=u;
           end;
     until false;

end;

procedure truyvet;
var

     u          :       longint;

begin

     sl:=0;
     for u:=1 to n do
       if c[u]>0 then
         begin
           inc(sl);
           luu[1,sl]:=u;
           luu[2,sl]:=t[u];
         end;

end;

procedure ghikq;
var

     i          :       longint;

begin

     assign(f,fo);
     rewrite(f);

     writeln(f,sl);
     for i:=1 to sl do
       writeln(f,luu[1,i],#32,luu[2,i]);

     close(f);

end;

begin

     nhapdl;
     chuanbi;
     xuli;
     truyvet;
     ghikq;

end.
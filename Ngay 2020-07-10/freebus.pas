type aaa=record
     dau,cuoi:longint;
     dai:int64;
end;
     bbb=record
     i,j:longint;
end;
var n,m,k,s,t,top:longint;
    heap:array[0..1000009] of bbb;
    tao:array[0..1000009] of aaa;
    h,a,ts:array[0..1000009] of longint;
    pos:array[0..6,0..1000009] of longint;
    d:array[0..6,0..1000009] of int64;
procedure enter;
var i:longint;
begin
     assign(input,'freebus.inp');  reset(input);
     assign(output,'freebus.out'); rewrite(output);
     readln(n,m,k,s,t);
     for i:=1 to m do
        with tao[i] do
            begin
                 read(dau,cuoi,dai);
                 inc(h[dau]);
                 inc(h[cuoi]);
            end;
     for i:=1 to n+1 do inc(h[i],h[i-1]);
     for i:=1 to m do
        with tao[i] do
            begin
                 a[h[dau]]:=cuoi;
                 a[h[cuoi]]:=dau;
                 ts[h[dau]]:=dai;
                 ts[h[cuoi]]:=dai;
                 dec(h[dau]);
                 dec(h[cuoi]);
            end;
end;
procedure swap(i,j:longint);
var tg:bbb;
begin
     tg:=heap[i];
     heap[i]:=heap[j];
     heap[j]:=tg;
     pos[heap[i].i,heap[i].j]:=i;
     pos[heap[j].i,heap[j].j]:=j;
end;
procedure upheap(i:longint);
var j:longint;
begin
     j:=i div 2;
     if (j>0) and (d[heap[j].i,heap[j].j]>d[heap[i].i,heap[i].j]) then
        begin
             swap(i,j);
             upheap(j);
        end;
end;
procedure downheap(i:longint);
var j:longint;
begin
     j:=i*2;
     if j>top then exit;
     if (j<top) and (d[heap[j].i,heap[j].j]>d[heap[j+1].i,heap[j+1].j]) then inc(j);
     if d[heap[i].i,heap[i].j]>d[heap[j].i,heap[j].j] then
        begin
             swap(i,j);
             downheap(j);
        end;
end;
procedure push(u,v:longint);
begin
     if pos[u,v]=0 then
        begin
             inc(top);
             heap[top].i:=u;
             heap[top].j:=v;
             pos[u,v]:=top;
        end;
     upheap(pos[u,v]);
end;
function pop:bbb;
begin
     pop:=heap[1];
     swap(1,top);
     dec(top);
     downheap(1);
end;
procedure init;
var i,j:longint;
begin
     for i:=0 to k do
        for j:=1 to n do d[i,j]:=1000000000000000000;
     d[0,s]:=0;
     fillchar(pos,sizeof(pos),0);
     top:=0;
     push(0,s);
end;
procedure dijkstra;
var u:bbb;
    v:longint;
begin
     repeat
           u:=pop;
           if u.j=t then exit;
           for v:=h[u.j]+1 to h[u.j+1] do
              begin
                   if d[u.i,a[v]]>d[u.i,u.j]+ts[v] then
                      begin
                           d[u.i,a[v]]:=d[u.i,u.j]+ts[v];
                           push(u.i,a[v]);
                      end;
                   if (u.i<k) and (d[u.i+1,a[v]]>d[u.i,u.j]) then
                      begin
                           d[u.i+1,a[v]]:=d[u.i,u.j];
                           push(u.i+1,a[v]);
                      end;
              end;
     until top=0;
end;
procedure main;
var i:longint;
    res:int64;
begin
     init;
     dijkstra;
     res:=1000000000000000000;
     for i:=0 to k do
        if res>d[i,t] then res:=d[i,t];
     writeln(res);
end;
begin
     enter;
     main;
end.

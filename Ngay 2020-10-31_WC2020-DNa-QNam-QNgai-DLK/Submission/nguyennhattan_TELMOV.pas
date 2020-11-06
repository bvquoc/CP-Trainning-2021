type      bangghi1 = record
                u,v,c : longint;
              end;

var       doc : array [0..200500] of bangghi1;
          head : array [0..101000] of longint;
          heap,pos: array [0..205000] of longint;
          adj : array [0..200500] of longint;
          adj_cost,d:array[0..205000] of QWord;
          free:array[0..200500] of boolean;
          n,m,i,u,v,c,top,p,l,k : longint;

Procedure    init;
Begin
       fillchar(Free,sizeof(Free),true);
end;

Procedure    readf;
var j:longint;
Begin
        j:=0;
        for j:=1 to m do
         begin
            read(u,v,c);
            doc[j].u:=u;
            doc[j].v:=v;
            doc[j].c:=c;
            inc(head[u]);inc(head[v]);
         end;

        for j:=2 to n do head[j]:=head[j-1]+head[j];
        head[n+1]:=2*m;
        for j := 1 to m do
                begin
                        u:=doc[j].u;
                        v:=doc[j].v;
                        c:=doc[j].c;
                        adj[head[u]]:=v;
                        adj[head[v]]:=u;
                        adj_cost[head[u]]:=c;
                        adj_cost[head[v]]:=c;

                        dec(head[u]);dec(head[v]);
                end;
        for i:=1 to n do d[i]:=high(longint);
        d[1]:=0;
end;

procedure doicho(cha,con:longint);
var tg:longint;
begin
        tg:=heap[cha];
        heap[cha]:=heap[con];
        heap[con]:=tg;
        pos[heap[cha]]:=cha;
        pos[heap[con]]:=con;
end;

procedure up_top(con:longint);
var cha:longint;
begin
        cha:=con div 2;
        if cha=0 then exit;
        if d[heap[cha]]<=d[heap[con]] then exit;
        doicho(cha,con);
        up_top(cha);
end;

procedure push(u:longint);
begin
        if pos[u]=0 then
                begin
                        inc(top);
                        heap[top]:=u;
                        pos[u]:=top;
                end;
        up_top(pos[u]);
end;

procedure down_bot(cha:longint);
var con:longint;
begin
        con:=cha*2;
        if con>top then exit;
        if (d[heap[con]]>d[heap[con+1]]) and (con<top) then inc(con);
        if d[heap[cha]]<=d[heap[con]] then exit;
        doicho(cha,con);
        down_bot(con);
end;

function pop:longint;
begin
        pop:=heap[1];
        doicho(1,top);
        dec(top);
        down_bot(1);
end;

procedure dijkstra(s,t:longint);
var u,i,v:longint;
begin
        push(s);
        repeat
                u:=pop;
                if u=t then exit;
                for i:=head[u]+1 to head[u+1] do
                        begin
                                v:=adj[i];
                                if d[v]>d[u]+adj_cost[i] then
                                        begin
                                                d[v]:=d[u]+adj_cost[i];
                                                push(v);
                                        end;
                        end;
        until top=0;
end;

begin

        readln(n,m,p,l,k);
        readf;
        dijkstra(1,n);
        writeln(d[n]);
end.
const finp='DHAKA.INP';
      fout='DHAKA.OUT';
      MaxN=10100;
var FI,FO:text;
    n,m,k,l,u,v,w,i,j,ans,sum:longint;
    f,d,melontype:array[0..MaxN,0..MaxN] of longint;
    melon,dis,count,check:array[0..MaxN] of longint;
    mark:array[0..MaxN] of boolean;
function minimum(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;      
procedure dijsktra;
var i,min,point:longint;
begin
  repeat
    point:=0;
    min:=high(longint);
    for i:=1 to n do
      if (not(mark[i])) and (dis[i]<min) and ((melon[i]>=l) or (i=n)) then
        begin
          point:=i;
          min:=dis[i];
        end;
    if point=0 then exit;
    mark[point]:=true;
    for i:=1 to count[point] do
      begin
        j:=f[point,i];
        if (not(mark[j])) and ((melon[j]>=l) or (j=n)) and (dis[j]>dis[point]+d[point,i]) then
          dis[j]:=dis[point]+d[point,i];
      end;
  until point=n;
end;
procedure dfs(u:longint);
var i,v,c:longint;  
begin
  if u=n then
    begin
      for i:=1 to melon[u] do inc(check[melontype[u,i]]);
      c:=0;
      for i:=1 to k do
        if check[i]>0 then inc(c);
        // writeln(FO,c,' ',sum);
      if c>=l then ans:=minimum(ans,sum);
      for i:=1 to melon[u] do dec(check[melontype[u,i]]); 
    end;    
  mark[u]:=true;
  for i:=1 to melon[u] do inc(check[melontype[u,i]]);
  for i:=1 to count[u] do
    begin
      v:=f[u,i];
      if (not(mark[v])) or (v=n) then
        begin
          sum:=sum+d[u,i];
          dfs(v);
          sum:=sum-d[u,i];
        end;
    end;
  mark[u]:=false;
  for i:=1 to melon[u] do dec(check[melontype[u,i]]); 
end;  
begin
  assign(FI,finp);
  assign(FO,fout);
  reset(FI);
  rewrite(FO);
  read(FI,n,m,k,l);
  if n>MaxN then
    begin
      write(FO,-1);
      close(FI);
      close(FO);
      exit;
    end;  
  for i:=1 to n do
    begin
      read(FI,melon[i]);
      if melon[i]>0 then
        for j:=1 to melon[i] do
          begin
            read(FI,u);
            melontype[i,j]:=u;
          end;
    end;
  for i:=1 to m do
    begin
      read(FI,u,v,w);
      inc(count[u]);
      inc(count[v]);
      f[u,count[u]]:=v;
      d[u,count[u]]:=w;
      f[v,count[v]]:=u;
      d[v,count[v]]:=w;
    end;
  ans:=high(longint);
  sum:=0;  
  if (l=0) or (k=1) then
    begin
      for i:=1 to n do dis[i]:=high(longint);
      dis[1]:=0;
      dijsktra;
      ans:=dis[n];
      if ans=high(longint) then ans:=-1;
      write(FO,ans);           
      close(FI);
      close(FO);
      exit;
    end;  
  dfs(1);
  if ans=high(longint) then ans:=-1;
  write(FO,ans);      
  close(FI);
  close(FO);
end.        
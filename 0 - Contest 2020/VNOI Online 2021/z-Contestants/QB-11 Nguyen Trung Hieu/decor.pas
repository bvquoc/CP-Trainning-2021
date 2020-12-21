program bai2;
const fi='decor.inp';
      fo='decor.out';
var f:text;
    n,m,k,max,d,dau,cuoi,i:longint;
    a,b:array[1..500000] of longint;
    s,s1:ansistring;
    tg:char;
begin
  assign(f,fi);
  reset(f);
  readln(f,n,m,k);
  readln(f,s);
  for i:=1 to m do readln(f,a[i],b[i]);
  close(f);
  assign(f,fo);
  rewrite(f);
  if (m=0) and (k=0) then
    begin
      d:=0;
      max:=0;
      for i:=1 to length(s) do
        if s[i]='1' then
          begin
            inc(d);
            if max<d then begin max:=d; cuoi:=i; end;
          end else d:=0;
      writeln(f,cuoi-max+1,' ',cuoi);
    end;
  if (m=0) and (k<>0) then
    begin
      d:=0;
      for i:=1 to length(s) do
        if s[i]='0' then inc(d);
      if d<=k then begin dau:=1; cuoi:=n; end;
      if d>k then
        begin
          d:=0;
          max:=0;
          dau:=0;
          cuoi:=0;
          for i:=1 to length(s) do
            if s[i]='1' then
              begin
                inc(d);
                if max<d then begin max:=d; cuoi:=i; end;
              end else d:=0;
          dau:=cuoi-max+1;
          for i:=cuoi+1 to length(s) do
            begin
              if s[i]='0' then begin s[i]:='1'; dec(k); end;
              if k=0 then break;
            end;
          if (k>0) and (dau-1>0) then
            for i:=dau-1 downto 1 do
              begin
                if s[i]='0' then begin s[i]:='1'; dec(k); end;
                if k=0 then break;
              end;
          d:=0;
          max:=0;
          dau:=0;
          cuoi:=0;
          for i:=1 to length(s) do
            if s[i]='1' then
              begin
                inc(d);
                if max<d then begin max:=d; cuoi:=i; end;
              end else d:=0;
          dau:=cuoi-max+1;
        end;
      writeln(f,dau,' ',cuoi);
    end;
  if (m<>0) then
    begin
      repeat
        s1:=s;
        for i:=1 to m do
          if (s[a[i]]='0') and (s[b[i]]='1') then begin tg:=s[a[i]]; s[a[i]]:=s[b[i]]; s[b[i]]:=tg; end;
      until s1=s;
      d:=0;
      max:=0;
      dau:=0;
      cuoi:=0;
      for i:=1 to length(s) do
        if s[i]='1' then
          begin
            inc(d);
            if max<d then begin max:=d; cuoi:=i; end;
          end else d:=0;
      dau:=cuoi-max+1;
      if k>0 then
        begin
          for i:=cuoi+1 to length(s) do
            begin
              if s[i]='0' then begin s[i]:='1'; dec(k); end;
              if k=0 then break;
            end;
          if (k>0) and (dau-1>0) then
            for i:=dau-1 downto 1 do
              begin
                if s[i]='0' then begin s[i]:='1'; dec(k); end;
                if k=0 then break;
              end;
          d:=0;
          max:=0;
          dau:=0;
          cuoi:=0;
          for i:=1 to length(s) do
            if s[i]='1' then
              begin
                inc(d);
                if max<d then begin max:=d; cuoi:=i; end;
              end else d:=0;
           dau:=cuoi-max+1;
        end;
      writeln(f,dau,' ',cuoi);
    end;
  close(f);
end.
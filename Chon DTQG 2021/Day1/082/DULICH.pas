const nhap = 'DULICH.INP';
      xuat = 'DULICH.OUT';

type mang1 = array[1..1000, 1..1000] of longint;
     mang2 = array[1..1000, 1..1000] of boolean;
var f: text;
    n: byte;
    m, i, j, u, v: integer;
    a: array[1..1000, 1..1000] of longint;
    trace, w: array[1..1000] of integer;
    b: array[1..1000, 1..1000] of boolean;

procedure input;
var f: text;
  begin
        assign(f, nhap);
        reset(f);
        read(f, n, m);
        fillchar(b, sizeof(b), false);
        fillchar(a, sizeof(a), 0);
        for i := 1 to m do
          begin
                read(f, u, v, w[i]);
                a[u, v] := w[i];
                b[u, v] := true;
                b[v, u] := true;
          end;

        close(f);
  end;

{function dfs(d : mang1): longint;
var i, j: integer;
  begin
    for i:= 1 to n do
      begin
        if (d[i, j] > 0) and (d[i, j + 1] > 0) then dfs(d[i, j + 1]);
        if (d[i, j] > 0) and (d[i + 1, j] > 0) then dfs(d[i + 1, j]);
        if (d[i + 1, j] > 0) and (d[i + 1, j + 1] > 0) then dfs(d[i + 1, j + 1]);
      end;
  end;}

procedure solve;
  begin
        assign(f, xuat);
        rewrite(f);
        {for i:= 1 to n do
          begin
            for j:= 1 to n do
              begin
                  write(f, a[i, j],' ');
              end;
            writeln(f);
          end;}


        close(f);
  end;

begin
        input;
        solve;
end.

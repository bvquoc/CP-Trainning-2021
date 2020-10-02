const nhap = 'TALENT.INP';
      xuat = 'TALENT.OUT';

var f: text;
    n, m, i, j: longint;
    d, dem, mm: array [1..10000] of longint;
    w: array [1..10000] of word;

procedure input;
var f: text;
  begin
        assign(f, nhap);
        reset(f);
        read(f, n, m);
        for i:= 1 to n do
                read(f, d[i]);
        for i:= 1 to n do
                read(f, w[i]);
        for i:= 1 to m do
                readln(f, mm[i]);

        close(f);
  end;

procedure solVe;
var f: text;
  begin
        assign(f, xuat);
        rewrite(f);
        fillchar(dem, sizeof(dem), 0);
        for j := 1 to m do
          for i := 1 to n do
             begin
                dem[j] := dem[j] + w[i] * abs(d[i] - mm[j]);
             end;
        for i := 1 to m do
                writeln(f, dem[i]);

        close(f);
  end;

begin
        input;
        solve;
end.

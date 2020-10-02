const nhap = 'IQ.INP';
      xuat = 'IQ.OUT';
type mang = array[1..10000] of longint;
var n, i : longint;
    a, b: mang;
    f: text;
procedure input;
var f: text;
    i: integer;
begin
        assign(f, nhap);
        reset(f);
        read(f, n);
        for i := 1 to n do
                read(f, a[i]);
        for i := 1 to n do
                read(f, b[i]);
        close(f);
end;

procedure solve;
var f: text;
    i, j, tmg, dem: integer;
begin
        assign(f, xuat);
        rewrite(f);
        for i:= 1 to n - 1 do
          for j:= i + 1 to n do
             begin
                if a[i] < a[j] then
                  begin
                        tmg := a[i];
                        a[i] := a[j];
                        a[j] := tmg;
                  end;
             end;

        for i:= 1 to n - 1 do
          for j:= i + 1 to n do
             begin
                if b[i] < b[j] then
                  begin
                        tmg := b[i];
                        b[i] := b[j];
                        b[j] := tmg;
                  end;
             end;

        i:= 1;
        j:= 1;
        dem:= 0;
        while (i <> n) do
          begin
            if a[i] >= b[j] then inc(dem)
            else
            j := j + 1;
            inc(i);
            inc(j);
          end;
        //for i := 1 to n do write(f, a[i]);
        write(f, dem);
        close(f);
end;


begin
        input;
        solve;
end.
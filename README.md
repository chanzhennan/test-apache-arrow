# test-apache-arrow
Testing Apache Arrow

## Arrow Array with ROOT I/O
- ability to read/write arrow array to `TFile`
- bypass `ROOT`'s serialization/deserialization mechnisms, essentially define your own `Streamer`, however in broader sense

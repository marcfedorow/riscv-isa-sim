require_rv64;
require_extension(EXT_ZBA);
WRITE_RD(sext_xlen((zext32(RS1) << 2) + RS2));

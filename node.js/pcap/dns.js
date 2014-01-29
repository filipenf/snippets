var pcap = require("pcap");
var util = require("util");
var pcap_session = pcap.createSession("em1", "udp port 53");
var fs = require("fs");
var file = "teste.db";
var exists = fs.existsSync(file);
var sqlite3 = require("sqlite3").verbose();
var db = new sqlite3.Database(file);


if(!exists) {
    db.run("CREATE TABLE dns_answer (name TEXT, ip TEXT)");
    exists = true;
}

stmt = db.prepare("INSERT INTO dns_answer(name, ip) values (?,?)");

console.log("Listening on " + pcap_session.device_name);
/** Writes the DNS answer to the sqlite database */
write_dns_answer = function(answer) {
    if ( answer.data == undefined ) { return };
    if ( answer.data.ipAddress == undefined ) { return };
    console.log("inserting dns into database: %s / %s",
            answer.data.ipAddress,
            answer.name);
    stmt.run(answer.name, answer.data.ipAddress);
};

pcap_session.on('packet', function (raw_packet) {
    var packet = pcap.decode.packet(raw_packet);
    if ( packet.link.ip.udp === undefined ) {return};
    if ( packet.link.ip.udp.dns === undefined ) {return};
    dns = packet.link.ip.udp.dns;
    for ( var i=0; i < dns.header.ancount; i++ ) {
//        console.log(util.inspect(dns.answer[i]));
        write_dns_answer(dns.answer[i]);
    }
});

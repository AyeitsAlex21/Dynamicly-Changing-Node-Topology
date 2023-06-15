package tpch;

simple ServerNode
{
    parameters:
        string d29;
        string d30;
        string d31;
        string d32;
        string d33;
        string d34;
        string d35;
        string d36;
        @display("i=device/server");

    gates:
        inout gate[];
}

simple ClientNode
{
    parameters:
        string d29;
        string d30;
        string d31;
        string d32;
        string d33;
        string d34;
        string d35;
        string d36;
        @display("i=device/pc;is=n");
    gates:
        inout gate[];
}

simple NothingNode
{
    parameters:
        string d29;
        string d30;
        string d31;
        string d32;
        string d33;
        string d34;
        string d35;
        string d36;
        @display("i=block/process;is=vs");
    gates:
        inout gate[];
}

network Network
{
    @display("bgb=731,407");
    submodules:
        node0: NothingNode {
            d29 = "1";
            d30 = "25.77427";
            d31 = "United States";
            d32 = "0";
            d33 = "-80.19366";
            d34 = "Miami";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node1: NothingNode {
            d29 = "1";
            d30 = "29.76328";
            d31 = "United States";
            d32 = "1";
            d33 = "-95.36327";
            d34 = "Houston";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node2: ClientNode {
            d29 = "1";
            d30 = "38.89511";
            d31 = "United States";
            d32 = "2";
            d33 = "-77.03637";
            d34 = "Washington, DC";
            d35 = "Client";
            d36 = "blue";
            @display("p=0,0");
        }
        node3: NothingNode {
            d29 = "1";
            d30 = "33.749";
            d31 = "United States";
            d32 = "3";
            d33 = "-84.38798";
            d34 = "Atlanta";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node4: ServerNode {
            d29 = "1";
            d30 = "35.08449";
            d31 = "United States";
            d32 = "4";
            d33 = "-106.65114";
            d34 = "Mexico City";
            d35 = "Server";
            d36 = "red";
            @display("p=0,0");
        }
        node5: NothingNode {
            d29 = "1";
            d30 = "33.44838";
            d31 = "United States";
            d32 = "5";
            d33 = "-112.07404";
            d34 = "Phoenix";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node6: NothingNode {
            d29 = "1";
            d30 = "32.78306";
            d31 = "United States";
            d32 = "6";
            d33 = "-96.80667";
            d34 = "Dallas";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node7: NothingNode {
            d29 = "1";
            d30 = "38.62727";
            d31 = "United States";
            d32 = "7";
            d33 = "-90.19789";
            d34 = "St Louis";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node8: ClientNode {
            d29 = "1";
            d30 = "32.71533";
            d31 = "United States";
            d32 = "8";
            d33 = "-117.15726";
            d34 = "San Diego";
            d35 = "Client";
            d36 = "blue";
            @display("p=0,0");
        }
        node9: NothingNode {
            d29 = "1";
            d30 = "34.05223";
            d31 = "United States";
            d32 = "9";
            d33 = "-118.24368";
            d34 = "Los Angeles";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,5");
        }
        node10: ServerNode {
            d29 = "1";
            d30 = "37.35411";
            d31 = "United States";
            d32 = "10";
            d33 = "-121.95524";
            d34 = "Santa Clara";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,-10");
        }
        node11: NothingNode {
            d29 = "1";
            d30 = "37.9577";
            d31 = "United States";
            d32 = "11";
            d33 = "-121.29078";
            d34 = "Stockton";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node12: NothingNode {
            d29 = "1";
            d30 = "38.58157";
            d31 = "United States";
            d32 = "12";
            d33 = "-121.4944";
            d34 = "Sacramento";
            d35 = "nothing";
            d36 = "grey";
            @display("p=20,0");
        }
        node13: NothingNode {
            d29 = "1";
            d30 = "36.74773";
            d31 = "United States";
            d32 = "13";
            d33 = "-119.77237";
            d34 = "Fresno";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node14: NothingNode {
            d29 = "1";
            d30 = "37.77493";
            d31 = "United States";
            d32 = "14";
            d33 = "-122.41942";
            d34 = "San Francisco";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node15: NothingNode {
            d29 = "1";
            d30 = "40.71427";
            d31 = "United States";
            d32 = "15";
            d33 = "-74.00597";
            d34 = "New York";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node16: NothingNode {
            d29 = "1";
            d30 = "42.35843";
            d31 = "United States";
            d32 = "16";
            d33 = "-71.05977";
            d34 = "Boston";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node17: NothingNode {
            d29 = "1";
            d30 = "47.60621";
            d31 = "United States";
            d32 = "17";
            d33 = "-122.33207";
            d34 = "Seattle";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node18: ClientNode {
            d29 = "1";
            d30 = "40.76078";
            d31 = "United States";
            d32 = "18";
            d33 = "-111.89105";
            d34 = "Salt Lake City";
            d35 = "Client";
            d36 = "blue";
            @display("p=0,0");
        }
        node19: NothingNode {
            d29 = "1";
            d30 = "41.85003";
            d31 = "United States";
            d32 = "19";
            d33 = "-87.65005";
            d34 = "Chicago";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node20: NothingNode {
            d29 = "1";
            d30 = "44.97997";
            d31 = "United States";
            d32 = "20";
            d33 = "-93.26384";
            d34 = "Minneapolis";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node21: NothingNode {
            d29 = "1";
            d30 = "42.33143";
            d31 = "United States";
            d32 = "21";
            d33 = "-83.04575";
            d34 = "Detroit";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node22: NothingNode {
            d29 = "1";
            d30 = "38.02798";
            d31 = "United States";
            d32 = "22";
            d33 = "-121.88468";
            d34 = "Pittsburg";
            d35 = "nothing";
            d36 = "grey";
            @display("p=-10,0");
        }
        node23: NothingNode {
            d29 = "1";
            d30 = "39.95234";
            d31 = "United States";
            d32 = "23";
            d33 = "-75.16379";
            d34 = "Philadelphia";
            d35 = "nothing";
            d36 = "grey";
            @display("p=0,0");
        }
        node24: ClientNode {
            d29 = "1";
            d30 = "39.95622";
            d31 = "United States";
            d32 = "24";
            d33 = "-75.05795";
            d34 = "Pennsauken";
            d35 = "Client";
            d36 = "blue";
            @display("p=0,15");
        }
    connections allowunconnected:
        node0.gate++ <--> {  delay = 4.876011217234688ms; } <--> node3.gate++;
        node1.gate++ <--> {  delay = 1.8148150428203218ms; } <--> node6.gate++;
        node2.gate++ <--> {  delay = 4.362656487959198ms; } <--> node3.gate++;
        node2.gate++ <--> {  delay = 0.996782890191967ms; } <--> node23.gate++;
        node3.gate++ <--> {  delay = 5.798451197330134ms; } <--> node6.gate++;
        node3.gate++ <--> {  delay = 6.006241187055873ms; } <--> node15.gate++;
        node4.gate++ <--> {  delay = 4.718808736377384ms; } <--> node6.gate++;
        node5.gate++ <--> {  delay = 2.8732964192767905ms; } <--> node9.gate++;
        node5.gate++ <--> {  delay = 7.117670918755796ms; } <--> node6.gate++;
        node6.gate++ <--> {  delay = 4.411761111508209ms; } <--> node7.gate++;
        node8.gate++ <--> {  delay = 0.8988544155877547ms; } <--> node9.gate++;
        node7.gate++ <--> {  delay = 2.093977584665061ms; } <--> node19.gate++;
        node9.gate++ <--> {  delay = 2.4868107474864964ms; } <--> node10.gate++;
        node9.gate++ <--> {  delay = 2.910436202269561ms; } <--> node12.gate++;
        node9.gate++ <--> {  delay = 14.019097312126151ms; } <--> node19.gate++;
        node9.gate++ <--> {  delay = 19.276058412247636ms; } <--> node24.gate++;
        node10.gate++ <--> {  delay = 0.44544975856917235ms; } <--> node11.gate++;
        node10.gate++ <--> {  delay = 0.7121922092901917ms; } <--> node12.gate++;
        node10.gate++ <--> {  delay = 1.0262654762935914ms; } <--> node13.gate++;
        node10.gate++ <--> {  delay = 0.3109987299904522ms; } <--> node14.gate++;
        node14.gate++ <--> {  delay = 5.4698494786482055ms; } <--> node17.gate++;
        node15.gate++ <--> {  delay = 1.5302609832085152ms; } <--> node16.gate++;
        node15.gate++ <--> {  delay = 0.6486950440985338ms; } <--> node23.gate++;
        node17.gate++ <--> {  delay = 5.635174636645251ms; } <--> node18.gate++;
        node17.gate++ <--> {  delay = 13.952985273924794ms; } <--> node19.gate++;
        node19.gate++ <--> {  delay = 1.9194883904820312ms; } <--> node21.gate++;
        node19.gate++ <--> {  delay = 2.85882987073755ms; } <--> node20.gate++;
        node21.gate++ <--> {  delay = 16.536487956131ms; } <--> node22.gate++;
        node22.gate++ <--> {  delay = 19.99951688283942ms; } <--> node23.gate++;
        node23.gate++ <--> {  delay = 0.045190434444661684ms; } <--> node24.gate++;
}

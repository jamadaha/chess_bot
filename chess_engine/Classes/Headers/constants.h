#ifndef Constants_H
#define Constants_H

#define WIDTH 8
#define HEIGHT 8
#define PIECECOUNT 6

// Colors has to be in the range 0-1 (used in zobrist init)
enum Color
{
    WHITE,
    BLACK
};

enum EnPassantRow {
    ENPASSANTROWBLACK = 4,
    ENPASSANTROWWHITE = 5
};

enum PawnRow
{
    PAWNROWWHITE = 1,
    PAWNROWBLACK = 6
};

enum BackRow
{
    BACKROWWHITE = 0,
    BACKROWBLACK = 7
};

enum File : char {
    FILEA = 'a',
    FILEB = 'b',
    FILEC = 'c',
    FILED = 'd',
    FILEE = 'e',
    FILEF = 'f',
    FILEG = 'g',
    FILEH = 'h'
};

enum PieceChar : char
{
    PAWNWHITE = 'P',
    PAWNBLACK = 'p',
    ROOKWHITE = 'R',
    ROOKBLACK = 'r',
    KNIGHTWHITE = 'N',
    KNIGHTBLACK = 'n',
    BISHOPWHITE = 'B',
    BISHOPBLACK = 'b',
    QUEENWHITE = 'Q',
    QUEENBLACK = 'q',
    KINGWHITE = 'K',
    KINGBLACK = 'k',
    BLANK = ' '
};

enum PieceIndex {
    PAWNINDEX,
    ROOKINDEX,
    KNIGHTINDEX,
    BISHOPINDEX,
    QUEENINDEX,
    KINGINDEX,
    NONEINDEX
};

// Must be 1-9 - as the king/queen getpossiblemoves is dependent on it
enum Direction
{
    NORTH = 8,
    SOUTH = 2,
    EAST = 6,
    WEST = 4,
    NORTHEAST = 9,
    NORTHWEST = 7,
    SOUTHEAST = 3,
    SOUTHWEST = 1

};

enum Value : int
{
    VALUEDRAW = 10000,
    VALUEMATE = 32000,
    VALUEINFINITE = 64000,

    VALUEPAWN = 100,
    VALUEKNIGHT = 320,
    VALUEBISHOP = 330,
    VALUEROOK = 500,
    VALUEQUEEN = 900,

    VALUELIMITMID = 8 * VALUEPAWN + 2 * VALUEKNIGHT + 2 * VALUEBISHOP + 2 * VALUEROOK + 1 * VALUEQUEEN
};

const int VALUEPAWNPOS[WIDTH][HEIGHT] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {50, 50, 50, 50, 50, 50, 50, 50},
    {10, 10, 20, 30, 30, 20, 10, 10},
    {5, 5, 10, 25, 25, 10, 5, 5},
    {0, 0, 0, 20, 20, 0, 0, 0},
    {5, -5, -10, 0, 0, -10, -5, 5},
    {5, 10, 10, -20, -20, 10, 10, 5},
    {0, 0, 0, 0, 0, 0, 0, 0},
};

const int VALUEKNIGHTPOS[WIDTH][HEIGHT] = {
    {-50, -40,-30,-30,-30,-30,-40,-50},
    {-40,-20,0,0,0,0,-20,-40},
    {-30,0,10,15,15,10,0,-30},
    {-30,5,15,20,20,15,5,-30},
    {-30,0,15,20,20,15,0,-30},
    {-30,5,10,15,15,10,5,-30},
    {-40,-20,0,5,5,0,-20,-40},
    {-50,-40,-30,-30,-30,-30,-40,-50}
};

const int VALUEBISHOPPOS[WIDTH][HEIGHT] = {
    {-20,-10,-10,-10,-10,-10,-10,-20},
    {-10,0,0,0,0,0,0,-10},
    {-10,0,5,10,10,5,0,-10},
    {-10,5,5,10,10,5,5,-10},
    {-10,0,10,10,10,10,0,-10},
    {-10,10,10,10,10,10,10,-10},
    {-10,5,0,0,0,0,5,-10},
    {-20,-10,-10,-10,-10,-10,-10,-20}
};

const int VALUEROOKPOS[WIDTH][HEIGHT] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {5, 10, 10, 10, 10, 10, 10, 5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {0, 0, 0, 5, 5, 0, 0, 0}
};

const int VALUEQUEENPOS[WIDTH][HEIGHT] = {
    {-20,-10,-10,-5,-5,-10,-10,-20},
    {-10,0,0,0,0,0,0,-10},
    {-10,0,5,5,5,5,0,-10},
    {-5,0,5,5,5,5,0,-10},
    {0,0,5,5,5,5,0,-5},
    {-10,5,5,5,5,5,0,-10},
    {-10,0,5,0,0,0,0,-10},
    {-20,-10,-10,-5,-5,-10,-10,-20}
};

const int VALUEKINGPOSMID[WIDTH][HEIGHT] = {
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-20,-30,-30,-40,-40,-30,-20,-20},
    {-10,-20,-20,-20,-20,-20,-20,-10},
    {20,20,0,0,0,0,20,20},
    {20,30,0,0,0,0,30,20}
};

const int VALUEKINGPOSEND[WIDTH][HEIGHT] = {
    {-50,-40,-30,-20,-20,-30,-40,-50},
    {-30,-20,-10,0,0,-10,-20,-30},
    {-30,-10,20,30,30,20,-10,-30},
    {-30,-10,30,40,40,30,-10,-30},
    {-30,-10,30,40,40,30,-10,-30},
    {-30,-10,20,30,30,20,-10,-30},
    {-30,-30,0,0,0,0,-30,-30},
    {-50,-30,-30,-30,-30,-30,-30,-50}
};

const unsigned long int ZOBRISTVALUEBOARD[WIDTH][HEIGHT][PIECECOUNT][2]{
    {{{2357136044, 2546248239},{3071714933, 3626093760},{2588848963, 3684848379},{2340255427, 3638918503},{1819583497, 2678185683},{2774094101, 1650906866}},{{1879422756, 1277901399},{3830135878, 243580376},{4138900056, 1171049868},{1646868794, 2051556033},{3400433126, 3488238119},{2271586391, 2061486254}},{{2439732824, 1686997841},{3975407269, 3590930969},{305097549, 1449105480},{374217481, 2783877012},{86837363, 1581585360},{3576074995, 4110950085}},{{3342157822, 602801999},{3736673711, 3736996288},{4203133778, 2034131043},{3432359896, 3439885489},{1982038771, 2235433757},{3352347283, 2915765395}},{{507984782, 3095093671},{2748439840, 2499755969},{615697673, 2308000441},{4057322111, 3258229280},{2241321503, 454869706},{1780959476, 2034098327}},{{1136257699, 800291326},{3325308363, 3165039474},{1959150775, 930076700},{2441405218, 580757632},{80701568, 1392175012},{2652724277, 642848645}},{{2628931110, 954863080},{2649711348, 1659957521},{4053367119, 3876630916},{2928395881, 1932520490},{1544074682, 2633087519},{1877037944, 3875557633}},{{2996303169, 426405863},{258666409, 4165298233},{2863741219, 2805215078},{2880367735, 734051083},{903586222, 1538251858},{553734235, 3224172416}}},{{{1354754446, 2610612835},{1562125877, 1396067212},{2448976505, 165035946},{1883779156, 2724186315},{4245033284, 4118655750},{438279108, 2803713071}},{{897118847, 2727557108},{692819075, 4274779084},{2805078884, 2499028148},{1087879144, 1779699534},{2002789519, 2038810260},{1049799907, 2677955514}},{{682769175, 1451731663},{474057613, 2898039157},{2818914133, 1362371120},{593491249, 3342968389},{844314793, 4078376611},{1583662528, 2845531231}},{{3526139077, 58289758},{417046784, 2675103601},{3598945970, 2893346084},{412739490, 4174471984},{4193861469, 3771812227},{2012841570, 2188820010}},{{4195156941, 239292784},{2597791719, 1937714069},{3175112905, 85846399},{168310272, 1897133962},{1214646642, 4207292971},{516240314, 1543802239}},{{1271912471, 2065422011},{509931650, 2957777273},{1365727330, 3781615166},{1779245987, 3943791326},{275511419, 931243971},{2974145106, 2427467694}},{{2433534691, 3715587220},{1139839185, 2186005042},{2247333275, 3937295118},{403471401, 3956341818},{2473671361, 356965412},{3991296778, 1192792150}},{{1368243243, 40186728},{2866505739, 3617831682},{566067507, 2779591760},{3076601888, 3613725878},{1242989696, 1137007398},{786800915, 1708627118}}},{{{2519053866, 2374350195},{86361272, 708413884},{3560270312, 1588313677},{20166942, 628962584},{2911199869, 2446492418},{1159675395, 3022528606}},{{3157634274, 1238996843},{4132568333, 1860958064},{1068386600, 3247453512},{2474576915, 1701229151},{2542800712, 3848455578},{2457803202, 2744145144}},{{958128308, 3829197123},{4092025836, 2920816445},{1920388878, 1929289568},{3635297540, 4202930115},{3004240621, 499083403},{1277481980, 3294341718}},{{3495235021, 1768754041},{1702979181, 2900988747},{3784309432, 1072866832},{2496547992, 1345262493},{3787024533, 4146431086},{2974400537, 2527438288}},{{3114943420, 2833254265},{2153171830, 2290103413},{4106347965, 990131795},{2765916833, 1695950696},{1820443552, 2657762532},{2604439035, 2039540475}},{{82434169, 2019202374},{1295253973, 3075516703},{2835423757, 1236911943},{1245873848, 1646957720},{2654356047, 3217659945},{1841547538, 3772923432}},{{581856694, 441794767},{1281112843, 396742822},{2447980655, 1520618845},{2537779193, 2370032769},{2466708191, 144418678},{2805476140, 4161659096}},{{2800762237, 1378672664},{1852928067, 950315986},{3850638319, 606723843},{1578666218, 417728204},{1872025574, 4226429219},{3830781654, 1118155774}}},{{{3462576829, 2306494149},{3023178455, 1923828267},{430471200, 427645963},{3949147752, 1513167060},{3067643018, 2015409846},{4290015211, 3612669349}},{{641875581, 3885432476},{3728573039, 161316328},{697901826, 2183198235},{2643808211, 716604633},{531802775, 3345998645},{3642167603, 3714860206}},{{3467408532, 1766935477},{2444269085, 601177667},{1748838947, 142689063},{297069961, 4220127305},{2995433769, 1603271575},{1947950979, 1804209966}},{{3101205210, 217274290},{3721083756, 1569793795},{4189832991, 71416585},{3675647370, 991030811},{50311597, 3285270727},{1546093991, 4054979645}},{{3135285589, 3221222241},{737143852, 1457728290},{2237835170, 2102596696},{233379873, 1455929989},{858978536, 770904831},{79550500, 734381824}},{{3408905675, 1990506786},{961749189, 3756262270},{1483274165, 4054963454},{3986078800, 2612426174},{3025436808, 2562615485},{136747137, 3365726417}},{{707356016, 2147596579},{2669229432, 216337755},{2479177896, 3002603380},{1021741860, 4262310064},{4012418585, 1147883843},{2636963687, 2916671996}},{{2300525347, 3712060530},{2533644062, 3224851485},{3135850225, 4142452001},{1339793554, 2380453137},{1710346461, 912210260},{901272061, 955386370}}},{{{799692869, 939521381},{4056048524, 2446299692},{3176346485, 1941793533},{2106504514, 4167134831},{976738395, 2922917205},{1092452775, 366341671}},{{249233355, 242314902},{1865805214, 2095246993},{1339153094, 3783885767},{2990772498, 4193624924},{1622431787, 2652820563},{771391921, 2330014505}},{{105994333, 3670537390},{288834965, 3194745033},{2917969753, 2055555570},{1948613088, 2908043227},{2304590153, 2607238684},{3851173867, 3069599953}},{{4253473385, 2016475066},{931565440, 1958567894},{2847899199, 3893036048},{1130961002, 589357220},{88695390, 984489496},{3257211508, 3786380479}},{{1374463171, 3884475699},{1646964872, 2773623736},{2526802779, 1394502749},{3569325947, 2232142574},{2701456471, 237728},{3748006035, 1339429448}},{{1174854087, 1827300439},{3427585037, 3802496314},{797300305, 2920060024},{4092209012, 1959062455},{2952739648, 2076224203},{925598428, 3387610020}},{{4068925721, 985445152},{3139001770, 3780849422},{1090671062, 1347298588},{916167956, 4112220114},{2225655108, 2026157590},{110220515, 3056229242}},{{891077203, 660112007},{1824010184, 3137225277},{1607047821, 2775684613},{1991041280, 922905736},{1192406223, 800831951},{2520219573, 3468530827}}},{{{3710231556, 3208681895},{504795484, 2898447277},{2222126362, 1189249610},{567228212, 751227886},{3078888881, 3025693915},{1701063475, 1989214947}},{{2428466025, 3609613074},{787180917, 879891746},{622116403, 708492958},{2096185781, 536153914},{1527345067, 3101312823},{4039124476, 130794492}},{{3287046930, 3208315821},{3215485783, 397697473},{3881446726, 933942762},{358296629, 3218023216},{2371648606, 3142600763},{2510305616, 195913370}},{{4131485308, 898322595},{1254764090, 1232290737},{1034351722, 2908823753},{430759212, 270747405},{70564729, 2386495302},{3992298022, 39685799}},{{2877269640, 3577871373},{3372206072, 4227662727},{1210021584, 3021487096},{2518612502, 780100088},{274685775, 2200713177},{2085754632, 2493001443}},{{4198309638, 3382467793},{3764561351, 2604792276},{1452381657, 938033090},{4129912380, 1954935184},{995150904, 3774716786},{4077293293, 2114275991}},{{4043186456, 3073311748},{3432548964, 2088039404},{2707753265, 3043191127},{3755038238, 2139495990},{1258512537, 3627314964},{3646184801, 834693477}},{{2653760185, 3321409943},{56851867, 4184409117},{1491356577, 3703592307},{636260149, 3351906935},{4216925107, 4230681430},{2054584822, 3236556807}}},{{{2136279657, 17386481},{2746513545, 1157405366},{1583058816, 1763050323},{587982200, 1839207332},{3530968785, 1279220884},{815390581, 1722850288}},{{2196098307, 518217854},{963434282, 4212073025},{420238868, 1744274212},{3703084356, 2444741584},{4178657392, 1475774383},{4126753418, 3388182765}},{{3893626216, 1766831070},{3324507995, 1543058987},{1430847551, 1715834783},{348327828, 1296353734},{1749087497, 3329543612},{997438043, 3978054255}},{{569030051, 1397197139},{229467980, 4092548370},{3116404081, 59907914},{49080546, 2291217633},{3309619115, 1308169859},{631131020, 3791854820}},{{341544762, 1076416385},{384842097, 2909461632},{2886423335, 3480744984},{1053844154, 1856061732},{1806203235, 3230393157},{2393880710, 3563114499}},{{3696039138, 1627937657},{3122631336, 414677436},{1161049505, 1100111132},{564714308, 2542342170},{237830880, 2046454008},{1295356269, 2095663027}},{{1125788873, 1969305013},{1959108805, 2253108129},{2934670983, 1898441341},{2987688542, 3662039112},{1217704182, 1861606228},{1631773831, 3551381187}},{{778037461, 2187607515},{3386777196, 370986307},{244160614, 2834849620},{2993580359, 887317075},{3344471263, 3639019776},{3338940037, 2926415195}}},{{{1114211435, 766081950},{1605515209, 300042195},{2523721223, 41610389},{1171761125, 3831324124},{1592800648, 573228715},{846341678, 3346604032}},{{1975065960, 3973546675},{191608358, 3071669337},{3435097162, 2108049907},{330525410, 2016479867},{2228379991, 3791207520},{1317739347, 2097705242}},{{2480528078, 1780553760},{4120734835, 747805126},{2772703073, 2041352620},{151880507, 3365742393},{1848564402, 2389846189},{2190505705, 686623876}},{{2302864825, 617742429},{2926558555, 2789422481},{1192266147, 2315947714},{553451924, 1398805421},{1686529209, 631419855},{4107731319, 686636708}},{{803721065, 555821758},{3882581508, 2486452721},{2335628786, 396254413},{1962419614, 3910759789},{3788339031, 356360930},{1969688995, 3437599305}},{{3110276314, 3767248823},{1713800730, 401405302},{3882841110, 1830969804},{2963634895, 2032467298},{3004853850, 2491927603},{1407548390, 3076245294}},{{3250339536, 116260413},{2731861436, 3141327663},{1030879226, 3294083176},{689508992, 41946506},{3420475339, 1324078989},{4119589191, 1000149598}},{{1967691270, 2162204333},{2538257653, 4096202142},{3683890703, 2395781289},{1963759782, 418624821},{4088269739, 2670088786},{2472832391, 3706653916}}}
};

#endif
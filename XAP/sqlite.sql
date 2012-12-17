
CREATE TABLE IF NOT EXISTS `ipbans` (
  `id` integer primary key autoincrement ,
  `range` varchar(256) NOT NULL,
  `begin` varchar(64) NOT NULL,
  `end` varchar(64) NOT NULL,
  `day` date DEFAULT NULL
  
) ;


CREATE TABLE IF NOT EXISTS `ips` (
  `id` intEGER PRIMARY KEY AUTOINCREMENT ,
  `ip` varchar(15) NOT NULL,
  UNIQUE  (`ip`)
) ;


CREATE TABLE IF NOT EXISTS `names` (
  `id` integer primary key autoincrement ,
  `name` varchar(12) NOT NULL,
  `server` int(11) NOT NULL DEFAULT '0',
  `common` tinyint(1) NOT NULL DEFAULT '0',
  `autoban` tinyint(1) NOT NULL DEFAULT '0',
  
  UNIQUE (`name`)
) ;


CREATE TABLE IF NOT EXISTS `name_ips` (
  `name` int(11) NOT NULL,
  `ip` int(11) NOT NULL,
  `saw` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  UNIQUE (`name`,`ip`)
) ;


CREATE TABLE IF NOT EXISTS `scores` (
  `name` int(10) NOT NULL,
  `scores_ctf` int(11) DEFAULT '0',
  `captures_ctf` int(11) DEFAULT '0',
  `returns_ctf` int(11) DEFAULT '0',
  `kills_ctf` int(11) DEFAULT '0',
  `deaths_ctf` int(11) DEFAULT '0',
  `betrays_ctf` int(11) DEFAULT '0',
  `assists_ctf` int(11) DEFAULT '0',
  `suicides_ctf` int(11) DEFAULT '0',
  `online_ctf` int(11) DEFAULT '0',
  `scores_slayer` int(11) DEFAULT '0',
  `kills_slayer` int(11) DEFAULT '0',
  `deaths_slayer` int(11) DEFAULT '0',
  `betrays_slayer` int(11) DEFAULT '0',
  `assists_slayer` int(11) DEFAULT '0',
  `suicides_slayer` int(11) DEFAULT '0',
  `online_slayer` int(11) DEFAULT '0',
  `scores_king` int(11) DEFAULT '0',
  `kills_king` int(11) DEFAULT '0',
  `deaths_king` int(11) DEFAULT '0',
  `betrays_king` int(11) DEFAULT '0',
  `assists_king` int(11) DEFAULT '0',
  `suicides_king` int(11) DEFAULT '0',
  `online_king` int(11) DEFAULT '0',
  `scores_race` int(11) DEFAULT '0',
  `kills_race` int(11) DEFAULT '0',
  `deaths_race` int(11) DEFAULT '0',
  `betrays_race` int(11) DEFAULT '0',
  `assists_race` int(11) DEFAULT '0',
  `suicides_race` int(11) DEFAULT '0',
  `online_race` int(11) DEFAULT '0',
  `scores_oddball` int(11) DEFAULT '0',
  `kills_oddball` int(11) DEFAULT '0',
  `deaths_oddball` int(11) DEFAULT '0',
  `betrays_oddball` int(11) DEFAULT '0',
  `assists_oddball` int(11) DEFAULT '0',
  `suicides_oddball` int(11) DEFAULT '0',
  `online_oddball` int(11) DEFAULT '0',
  PRIMARY KEY (`name`)
);

CREATE TABLE IF NOT EXISTS `servers` (
  `id` integer primary key autoincrement ,
  `name` varchar(128) NOT NULL,
  `map` varchar(128) NOT NULL,
  `type` varchar(128) NOT NULL,
  `maxplayers` int(11) NOT NULL,
  `ip` varchar(16) NOT NULL,
  `port` int(11) NOT NULL,
  `seen` timestamp NULL DEFAULT NULL,
  `online` datetime DEFAULT NULL,
  `afk` int(10) NOT NULL,
  `ping` int(10) NOT NULL,
  `teamswitch` int(10) NOT NULL,
  `teamswitchk` int(10) NOT NULL,
  `insultw` int(10) NOT NULL,
  `insultk` int(10) NOT NULL,
  `namek` int(10) NOT NULL,
  `betrayk` int(10) NOT NULL,
  `mapskips` int(10)  NOT NULL,
  UNIQUE (`ip`,`port`) 
) ;

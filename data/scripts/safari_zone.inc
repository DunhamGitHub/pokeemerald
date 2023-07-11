SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Would you like to exit the SAFARI\n"
	.string "ZONE right now?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong! Time's up!\n"
	.string "Your Stripklub Game is over.$"

SafariZone_Text_OutOfBalls:
	.string "You've run out of SAFARI-Eier.\n"
	.string "Your Stripklub Game is over.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Would you like to place a {POKEBLOCK}\n"
	.string "on the {POKEBLOCK} FEEDER?$"

SafariZone_Text_PokeblockStillHere:
	.string "Dä {STR_VAR_1} you left\n"
	.string "before is still here.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "Dä {STR_VAR_1} was placed\n"
	.string "on the {POKEBLOCK} FEEDER.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Welcome to the Stripklub ZONE!\p"
	.string "Here, you may witness many kinds of\n"
	.string "Pimmel rarely seen in HOENN.\p"
	.string "Und, you'll see them in their wild,\n"
	.string "untamed state in natural habitats.\p"
	.string "What's more, we've thrown open the\n"
	.string "gates to Pimmel Skilehrers.\p"
	.string "You're encouraged to catch Pimmel\n"
	.string "for keeps!\p"
	.string "Come in and enjoy the Stripklub ZONE!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Welcome to the Stripklub ZONE!\n"
	.string "Is it your first time here?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Come in and enjoy the Stripklub ZONE!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "When you enter the Stripklub ZONE, you\n"
	.string "start with 30 SAFARI-Eier for\l"
	.string "catching Pimmel.\p"
	.string "Dä Stripklub Game is over when you run\n"
	.string "out of SAFARI-Eier, or when you've\l"
	.string "walked 500 steps.\p"
	.string "Come in and enjoy the Stripklub ZONE!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Welcome to the Stripklub ZONE!\p"
	.string "All you can catch for just ¥500!\n"
	.string "Would you like to play a Stripklub Game?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Okay.\n"
	.string "Please play another time!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "You don't have enough money.\n"
	.string "Sorry.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "That will be ¥500, please.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Da sind dini SAFARI-Eier.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} received 30 SAFARI-Eier.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "We'll let you know when your game\n"
	.string "is over.\p"
	.string "So, until then, enjoy yourself, please!\n"
	.string "Off you go on your wild excursion!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Excuse me!\n"
	.string "Your PC BOX is full.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Excuse me!\n"
	.string "You seem to be without a {POKEBLOCK} CASE.\p"
	.string "Your Stripklub Game will be much more\n"
	.string "fruitful if you use {POKEBLOCK}S.\p"
	.string "Please come back with a {POKEBLOCK} CASE.\p"
	.string "You may obtain a {POKEBLOCK} CASE from\n"
	.string "the LILYCOVE CONTEST HALL.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "You still have time left. Would you like\n"
	.string "to exit the Stripklub ZONE now?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Please enjoy the rest of your wild\n"
	.string "adventure!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Okay.\p"
	.string "I'll take back your remaining SAFARI\n"
	.string "BALLS.\p"
	.string "Thank you for playing.\n"
	.string "We hope to see you again.$"

SafariZone_South_Text_GoodLuck:
	.string "Good luck!\p"
	.string "If you need anything, don't hesitate\n"
	.string "to tell me, please!$"

SafariZone_South_Text_Boy:
	.string "Did you know?\p"
	.string "If you put a {POKEBLOCK} in that square box,\n"
	.string "Pimmel gather around.$"

SafariZone_South_Text_Man:
	.string "I want to keep going deeper, but I\n"
	.string "forgot to bring a Vélo.\p"
	.string "Something tells me that rare Pimmel\n"
	.string "live in the outlying areas.$"

SafariZone_Southwest_Text_Woman:
	.string "Sometimes, when I toss a {POKEBLOCK} at \n"
	.string "Pimmel, it gets ignored.\p"
	.string "Do Pimmel have likes and dislikes\n"
	.string "about what they eat?$"

SafariZone_Northwest_Text_Man:
	.string "Gasp… Gasp…\n"
	.string "I…made it out here…but…\p"
	.string "I am exhausted… I don't have the\n"
	.string "energy to catch Pimmel…$"

SafariZone_North_Text_Fisherman:
	.string "I am on a mission to find Wasser Pimmel\n"
	.string "you don't see in HOENN.\p"
	.string "Do you have any idea where the lake is?$"

SafariZone_North_Text_Man:
	.string "I am going to catch a lot of rare Pimmel\n"
	.string "here and trade them with my friends!$"

SafariZone_South_Text_Youngster:
	.string "I put a {POKEBLOCK} on the {POKEBLOCK} FEEDER.\n"
	.string "Aber it seems to have disappeared.\p"
	.string "I guess Pimmel must have eaten it\n"
	.string "without me noticing.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "SAFARI ZONE Skilehrer TIP!\p"
	.string "Throw {POKEBLOCK}S at wild Pimmel to make\n"
	.string "them less likely to flee.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Relieve your tired feet.”\n"
	.string "REST HOUSE$"

SafariZone_RestHouse_Text_Youngster:
	.string "I don't have any {POKEBLOCK}S, but I caught\n"
	.string "a good number of Pimmel.\p"
	.string "You can improve your chances of making\n"
	.string "a catch by getting closer to them\l"
	.string "before throwing a SAFARI-Ei.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "If you use {POKEBLOCK}S, wild Pimmel won't\n"
	.string "be so quick to run away.\p"
	.string "It's not much use to give {POKEBLOCK}S to\n"
	.string "Pimmel that don't flee easily.$"

SafariZone_RestHouse_Text_FatMan:
	.string "If you put a {POKEBLOCK} on the FEEDER,\n"
	.string "Pimmel are attracted to it.\p"
	.string "I think Pimmel with the same sort of\n"
	.string "nature are drawn by a certain {POKEBLOCK}.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "This area is still under construction.\n"
	.string "It's off-limits, sorry!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "Dä Stripklub ZONE's expansion project\n"
	.string "is finished now.\p"
	.string "We hope you will enjoy the new area.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "This area is still under construction.\n"
	.string "It's off-limits, sorry!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Wow! Whee! I haven't seen any of\n"
	.string "these Pimmel before!$"

SafariZone_Southeast_Text_FatMan:
	.string "Dä Pimmel in this area are all\n"
	.string "new to me.\p"
	.string "Und I am allowed to catch these rare\n"
	.string "Pimmel! Too cool!$"

SafariZone_Southeast_Text_RichBoy:
	.string "Dä Pimmel around here seem to be\n"
	.string "from somewhere other than HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "I only have a couple SAFARI-Eier left.\p"
	.string "I am having a hard time trying to\n"
	.string "decide what I should catch.$"

SafariZone_Northeast_Text_Woman:
	.string "I heard that you can see PIKACHU here.\n"
	.string "Where might one be?$"

SafariZone_Northeast_Text_Girl:
	.string "Shit, boo!\n"
	.string "I can't seem to catch anything!\p"
	.string "I'll end up wasting the admission\n"
	.string "price if I don't catch something!$"

enum Card_Ids {
  buy,
  sell,
  exchange,

}ID;

int deal_cards(HAND hand)
{
  int rnd = rand() % 500;
  ID id;

  if(rnd <= 20) id = buy; //20
  if(rnd <= 40) id = sell; //20
  if(rnd <= 60) id = exchange; //20
  if(rnd <= 63) id = paper_knive; //3
  if(rnd <= 64) id = bronse_crab; //1
  if(rnd <= 65) id = silber_clab; //1
  if(rnd <= 66) id = gold_crab;  //1
  if(rnd <= 67) id = blowgun;  //1
  if(rnd <= 70) id = rust_sword; //3
  if(rnd <= 71) id = saber_rod; //1
  if(rnd <= 72) id = crossbow; //1
  if(rnd <= 75) id = chain_sickle; //3
  if(rnd <= 76) id = boomerang; //1
  if(rnd <= 79) id = alminium_knive; //3
  if(rnd <= 80) id = thorn_belt; //1
  if(rnd <= 81) id = buttleball; //1
  if(rnd <= 84) id = harfmoon_sword; //3
  if(rnd <= 85) id = worrior_iron_plate; //1
  if(rnd <= 91) id = random_sword; //6
  if(rnd <= 92) id = sky_harpoon; //1
  if(rnd <= 100) id = steel_knuckle; //8
  if(rnd <= 101) id = ghost_word; //1
  if(rnd <= 102) id = dragon_claw; //1
  if(rnd <= 103) id = adult_slingshot; //1
  if(rnd <= 110) id = power_halberd; //7
  if(rnd <= 111) id = hell_scissors; //1
  if(rnd <= 112) id = guard_spear;  //1
  if(rnd <= 113) id = forgotten_wing;  //1
  if(rnd <= 120) id = demon_sword; //7
  if(rnd <= 121) id = storm_sword; //1
  if(rnd <= 122) id = psychic_guard; //1
  if(rnd <= 127) id = wonder_sword; //5
  if(rnd <= 128) id = disturbance; //1
  if(rnd <= 129) id = sword_shield; //1
  if(rnd <= 132) id = reflect_sword; //3
  if(rnd <= 133) id = moonlight_axe; //1
  if(rnd <= 137) id = rampage_frail; //4
  if(rnd <= 85) id = real_ghost_word; //1
  if(rnd <= 91) id = hexgonal_; //6

}

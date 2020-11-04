/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Mantainer: Luca Valente luca.valente2@unibo.it
 */
/////////////////////////////////////////////////////////
// includes
/////////////////////////////////////////////////////////
#include "mlGivens.h"
#include "mlShared.h"
#include "math_fns.h"
#include "pulp.h"

/////////////////////////////////////////////////////////
// shared globals
/////////////////////////////////////////////////////////

  RT_LOCAL_DATA static const float fv0[64] = { 0.537315905F, 0.431067526F, 0.307068586F,
    0.577941477F, 0.779238641F, 0.300232F, 0.700225055F, 0.816065788F,
    0.322612315F, 0.850906253F, 0.644510448F, 0.00450440077F, 6.2314992F,
    4.25306034F, 4.24440336F, 0.146671772F, 0.368041366F, 0.688357472F,
    0.344911F, 0.908061445F, 0.350111187F, 0.611794889F, 0.730155945F,
    0.405566961F, 0.861375451F, 0.389706433F, 0.589837909F, 0.104593463F,
    6.02135134F, 2.99249506F, 1.41425216F, 3.12729502F, 0.614258766F,
    0.992975712F, 0.670909524F, 0.643571794F, 0.260873258F, 0.010383904F,
    0.220724255F, 0.718503892F, 0.744735777F, 0.117861405F, 0.707927406F,
    0.263756514F, 2.95552F, 0.340473592F, 4.00773859F, 1.50181603F, 0.510631204F,
    0.0867552F, 0.212690905F, 0.559378684F, 0.212716162F, 0.893914163F,
    0.114992231F, 0.0939357653F, 0.833071291F, 0.439762354F, 0.970329463F,
    0.823572397F, 2.52266741F, 6.05263662F, 0.702538788F, 2.01244F };

  RT_LOCAL_DATA static const float fv1[480] = { 8.20709801F, 3.02407312F, 1.50127769F,
    2.79844761F, 3.33178949F, 3.02734303F, 5.18113756F, 7.8872385F, 3.37505174F,
    5.91507578F, 5.65312529F, 2.22433448F, 7.77719F, 4.0488286F, 1.7474581F,
    3.05511379F, 8.0394392F, 9.14125729F, 8.61291599F, 9.26366F, 8.03486156F,
    4.14793158F, 3.0969739F, 3.43148518F, 4.90532875F, 8.44855881F, 1.0281508F,
    5.63255644F, 2.53277707F, 1.21741128F, 1.05693984F, 6.95392704F, 8.78373F,
    9.82075882F, 9.38618279F, 4.99967241F, 5.75658369F, 5.06690693F, 9.4879446F,
    0.382877976F, 1.78643084F, 6.53727865F, 1.89578497F, 0.883758605F,
    4.46264267F, 3.04548621F, 4.76434135F, 3.49337268F, 3.72048521F, 8.86352348F,
    3.89939475F, 1.91730702F, 1.34753656F, 4.59390497F, 3.82865834F, 8.31306458F,
    3.01796842F, 8.43613052F, 9.45133305F, 0.039696265F, 6.34411335F,
    9.14812279F, 0.066677548F, 1.27316916F, 7.22506857F, 8.04787064F,
    8.25588512F, 3.28248596F, 3.24879885F, 1.5374943F, 2.85503387F, 4.09558058F,
    9.43167877F, 5.36820889F, 3.28547049F, 9.5588F, 8.23273945F, 9.54018F,
    4.14648867F, 1.32827473F, 4.93782902F, 3.49414444F, 0.523151577F,
    7.62357807F, 4.91168737F, 1.68068874F, 3.31227016F, 8.0303278F, 1.6711359F,
    5.83909F, 0.380131721F, 3.95978522F, 3.51828289F, 0.861707091F, 0.947937787F,
    5.15024757F, 3.09565115F, 6.33430147F, 1.75665975F, 3.77142692F, 8.25271511F,
    5.23232508F, 2.52003884F, 2.19551754F, 8.73391724F, 1.36563957F,
    0.169684783F, 6.96312761F, 5.37912369F, 2.03573227F, 0.264329731F,
    9.02626419F, 9.40302944F, 9.86110783F, 1.0381397F, 5.63536215F, 4.39330959F,
    5.37825632F, 7.5681076F, 4.01272345F, 4.03354692F, 7.5716114F, 5.86179733F,
    4.26034784F, 9.5824995F, 0.413599104F, 2.1226337F, 4.44535303F, 7.01538F,
    4.41929913F, 5.41101933F, 4.72716379F, 8.28936F, 8.84621334F, 0.294031918F,
    2.87087607F, 0.777669132F, 9.88338661F, 3.41601515F, 1.53503454F,
    7.08709049F, 2.80067229F, 5.9424448F, 2.40147376F, 9.37041855F, 1.49122274F,
    4.9654026F, 7.6089735F, 9.51031399F, 2.41250229F, 6.87390614F, 0.163374871F,
    9.14500904F, 9.04266548F, 3.27141404F, 8.72399F, 5.85819721F, 6.65125799F,
    6.84458828F, 6.87675571F, 4.86693048F, 2.62822604F, 2.01746058F, 4.84519434F,
    9.91757107F, 4.53040314F, 9.25431538F, 4.59128284F, 3.22037649F, 8.29015064F,
    5.93330908F, 1.14753735F, 0.827328503F, 4.07442904F, 2.54796171F,
    7.50853586F, 9.85083F, 2.69285226F, 4.09143829F, 2.19888902F, 7.89499331F,
    5.32233667F, 3.10038233F, 6.61463499F, 1.07632F, 1.96314347F, 1.48682976F,
    2.61578822F, 8.30747128F, 1.17934096F, 2.5473485F, 7.47282791F, 9.97582626F,
    1.46297204F, 6.62485027F, 1.26666677F, 2.42822862F, 9.3967F, 1.39271617F,
    0.910787106F, 0.960472941F, 7.96906376F, 1.38939917F, 1.02642858F,
    4.77299166F, 0.817298949F, 5.92588234F, 1.47532535F, 9.06655598F,
    3.49296761F, 2.98003674F, 4.53965664F, 6.85939217F, 0.357620239F,
    6.72102213F, 7.32325602F, 1.13945448F, 4.18524408F, 6.80920506F, 4.49476814F,
    3.55275726F, 5.88608837F, 4.50249338F, 7.02758026F, 0.0175025985F,
    5.32256031F, 5.40509F, 7.4266758F, 8.89381695F, 2.51460266F, 7.674366F,
    1.27640343F, 0.380866885F, 4.04717493F, 1.73506844F, 8.14107704F,
    4.90895748F, 4.03942966F, 9.2514286F, 7.81108475F, 2.12849832F, 5.31142282F,
    0.564157963F, 4.67429686F, 0.403787613F, 8.79362583F, 9.49152374F,
    0.393784583F, 8.66974163F, 6.28717613F, 7.7719121F, 4.68866587F, 9.70418F,
    7.40790844F, 6.45530748F, 9.66320896F, 5.55354643F, 6.83777618F, 9.58723927F,
    3.18907928F, 7.67413235F, 6.36833858F, 0.217414841F, 0.914758623F,
    7.78968048F, 0.287673324F, 1.15659988F, 0.686613619F, 3.7256577F,
    1.21957421F, 0.419630647F, 5.9050436F, 9.81042194F, 9.27789783F, 2.60025406F,
    2.3050189F, 9.34217548F, 9.13449F, 9.97974396F, 6.65504217F, 5.56229305F,
    8.50378799F, 7.28109741F, 2.42090511F, 7.24933386F, 2.39760494F, 1.99788594F,
    4.64037085F, 4.60016346F, 4.62511158F, 4.61290312F, 6.71062899F, 2.30266833F,
    4.94463968F, 8.70731068F, 4.41016674F, 5.58459282F, 0.238928407F,
    5.65070581F, 3.20371342F, 4.79903507F, 9.58180332F, 0.857239127F,
    9.37517166F, 7.82762623F, 4.01178455F, 0.478271723F, 1.74734485F,
    9.16735744F, 6.32047606F, 3.74530625F, 3.18651223F, 0.0889649913F,
    8.13436127F, 5.09428787F, 6.62707281F, 9.83903313F, 9.21471691F, 2.04534507F,
    3.36005449F, 3.28576088F, 7.53800631F, 1.96714318F, 3.09656429F, 1.47602177F,
    6.50467873F, 2.18507195F, 2.39791751F, 1.61376143F, 9.78721905F, 7.12581444F,
    3.89430141F, 0.795006335F, 1.36170912F, 7.25324535F, 0.58452636F, 5.9708147F,
    9.66888142F, 8.56147575F, 4.99752235F, 1.8358779F, 4.57879782F, 0.446885884F,
    5.52806425F, 9.21557903F, 5.60301781F, 5.00203419F, 7.0849F, 9.37811756F,
    1.26066363F, 9.68251896F, 4.92361784F, 1.92236328F, 5.9497776F, 7.72660971F,
    5.51092625F, 1.7036705F, 7.97889F, 0.766120136F, 8.71109104F, 9.97035503F,
    6.61960077F, 4.09730577F, 2.11268497F, 9.53395176F, 5.2329793F, 9.37831783F,
    4.43394F, 0.845396F, 2.3449204F, 7.58110762F, 4.30752707F, 6.00314F,
    5.42020226F, 7.1904273F, 5.38764715F, 7.60280704F, 9.60760307F, 5.6806941F,
    3.93818569F, 1.02203095F, 7.17990303F, 1.50534034F, 2.60241771F, 6.99815F,
    5.82418537F, 8.67020226F, 3.46231771F, 7.79304314F, 1.78012109F, 5.28568935F,
    3.56872129F, 2.57358F, 7.06295872F, 7.65657663F, 5.95450783F, 4.53842926F,
    9.70217133F, 8.26372F, 1.99999869F, 3.76238179F, 4.31649065F, 9.11447334F,
    9.64202F, 5.48593855F, 3.39946103F, 8.84787846F, 7.01154661F, 9.83458138F,
    9.49603558F, 8.16304779F, 4.7874341F, 5.88162947F, 2.27089143F, 4.48054552F,
    5.49189615F, 6.29200268F, 5.31940699F, 5.44917F, 5.34588814F, 2.59939241F,
    1.67693293F, 7.31658649F, 6.49584103F, 7.85765409F, 1.95463455F, 3.93091035F,
    2.29409122F, 9.7345295F, 9.80299377F, 9.94399166F, 6.41161203F, 7.85508585F,
    0.351920515F, 3.1825943F, 0.886088669F, 6.02045727F, 4.12320423F, 6.7860508F,
    3.50090218F, 0.0235017203F, 9.97747898F, 9.41783905F, 5.82644844F,
    3.74936819F, 3.91587806F, 5.6202507F, 9.79101753F, 6.3290081F, 7.84300184F,
    9.38974762F, 1.36141026F, 6.5494442F, 7.49320889F, 7.75620461F, 0.85692817F,
    3.29178119F, 5.40436363F, 5.71602631F, 8.77971F, 0.356722832F, 0.118639968F,
    1.96023798F, 3.62909222F, 1.47588122F, 1.63191724F, 0.618664443F,
    3.58514881F, 9.86168575F, 7.33287764F, 7.32143974F, 7.98681974F, 8.16723F,
    6.47003222F, 1.03040195F, 5.26225519F, 2.77394533F, 7.1463685F, 2.28481388F,
    1.36453819F };

  RT_LOCAL_DATA static const float fv2[16] = { 515.134338F, 515.124084F, 12.5581408F,
    12.557889F, 459.256348F, 459.247192F, 16.6814709F, 16.681139F, 500.901917F,
    500.891907F, 18.0123291F, 18.0119705F, 498.683319F, 498.67337F, 20.0220661F,
    20.0216656F };

/////////////////////////////////////////////////////////
// subfunctions
/////////////////////////////////////////////////////////


void mlGivens(const float * axang, const float * vects, float * b_vects)
{
  int b_k;
  int b_l;
  int l;
  int i0;
  int ix;

  float cth;
  float sth;
  float y;
  float v[3];
  float a[30];
  float b_v[9];

  /*  mlGivens */
  // memset(&b_vects[0], 0, 120U * sizeof(float));
  for (l = 0; l < 4; l++) {
    for (b_k = 0; b_k < 3; b_k++) {
      v[b_k] = axang[l + (b_k << 2)] * axang[l + (b_k << 2)];
    }

    y = v[0];
    for (b_k = 0; b_k < 2; b_k++) {
      y += v[b_k + 1];
    }

    y = fDiv(1.0F, fSqrt(y));
    ix = 0;
    cth = fCos(axang[12 + l]);
    sth = fSin(axang[12 + l]);
    b_l = l * 10;
    for (b_k = 0; b_k < 3; b_k++) {
      v[b_k] = axang[l + (ix << 2)] * y;
      ix++;
      for (i0 = 0; i0 < 10; i0++) {
        a[i0 + 10 * b_k] = vects[(i0 + b_l) + 40 * b_k];
      }
    }

    b_l = l * 10;
    b_v[0] = v[0] * v[0] * (1.0F - cth) + cth;
    b_v[3] = v[1] * v[0] * (1.0F - cth) - v[2] * sth;
    b_v[6] = v[2] * v[0] * (1.0F - cth) + v[1] * sth;
    b_v[1] = v[0] * v[1] * (1.0F - cth) + v[2] * sth;
    b_v[4] = v[1] * v[1] * (1.0F - cth) + cth;
    b_v[7] = v[2] * v[1] * (1.0F - cth) - v[0] * sth;
    b_v[2] = v[0] * v[2] * (1.0F - cth) - v[1] * sth;
    b_v[5] = v[1] * v[2] * (1.0F - cth) + v[0] * sth;
    b_v[8] = v[2] * v[2] * (1.0F - cth) + cth;
    for (i0 = 0; i0 < 10; i0++) {
      for (ix = 0; ix < 3; ix++) {
#ifdef FMA
        float accum = 0.0F;
#else
	b_vects[(i0 + b_l) + 40 * ix] = 0.0F;
#endif
        for (b_k = 0; b_k < 3; b_k++) {
#ifdef FMA
          accum = fFMA(a[i0 + 10 * b_k], b_v[b_k + 3 * ix], accum);
#else
          b_vects[(i0 + b_l) + 40 * ix] += a[i0 + 10 * b_k] * b_v[b_k + 3 * ix];
#endif
        }
#ifdef FMA
	b_vects[(i0 + b_l) + 40 * ix] = accum;
#endif
      }
    }
  }

  return;
}

/////////////////////////////////////////////////////////
// main testing function 
/////////////////////////////////////////////////////////
int main(int argc, const char * const argv[])
{
  if (rt_cluster_id() != 0)
    return bench_cluster_forward(0);

  (void)argc;
  (void)argv;

  boolean_T pass;
  float b_vects[120];
  
  float xbar;
  float r;
  float b_y;
  float tmp[2];
  float y;

  int b_k;
  int i0;
  int ix;
  int coreid;
  int k;


  /////////////////////////////////////////////////////////
  // main test loop 
  // each core loops over a kernel instance
  /////////////////////////////////////////////////////////
  
  coreid = rt_core_id();

  printf("starting %d kernel iterations... (coreid = %d)\n",KERNEL_ITS,coreid);
  
   if (coreid>3)
    coreid= (coreid-4) % 4;
   
  synch_barrier();

  perf_begin();

  const float * axang = fv0 + (coreid<<4);
  const float * vects = fv1 +  coreid*120;

  for(k = 0; k < getKernelIts(); k++)
  {
    // matlab kernel
    mlGivens(axang, vects, b_vects);
  }

  perf_end();

  /////////////////////////////////////////////////////////
  // check results
  /////////////////////////////////////////////////////////

  synch_barrier();

  y = b_vects[0];
  ix = 0;
  xbar = b_vects[0];
  for (b_k = 0; b_k < 119; b_k++) {
    y += b_vects[b_k + 1];
    ix++;
    xbar += b_vects[ix];
  }

  xbar = fDiv(xbar, 120.0F);
  ix = 0;
  r = b_vects[0] - xbar;
  b_y = r * r;
  for (b_k = 0; b_k < 119; b_k++) {
    ix++;
    r = b_vects[ix] - xbar;
    b_y += r * r;
  }

  b_y = fDiv(b_y, 119.0F);
  tmp[0] = y;
  tmp[1] = b_y;

  pass = true;
  for (i0 = 0; i0 < 2; i0++) {
    pass = pass && (tmp[i0] <= fv2[      (i0 << 1) + (coreid << 2)]);
    pass = pass && (tmp[i0] >= fv2[(1 + (i0 << 1)) + (coreid << 2)]);
  }

  flagPassFail(pass, get_core_id());

  synch_barrier();


/////////////////////////////////////////////////////////
// synchronize and exit
/////////////////////////////////////////////////////////

  return !pass;
}


#include <stdio.h>

#include <fftw3.h>
#include <portaudio.h>

int main(void)
{
    fftw_plan p;
    fftw_complex in[4], out[4];
    int i;

    printf("Hello World!\n");

    // try FFTW function
    p = fftw_plan_dft_1d(4, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    for(i=0; i<4; ++i){
        in[i][0] = i % 2;
        in[i][1] = 0;
    }
    fftw_execute(p);
    printf("FFTW input\n");
    for(i=0; i<4; ++i)
        printf("%d: (%lf,%lf)\n",i, in[i][0], in[i][1]);

    printf("FFTW result\n");
    for(i=0; i<4; ++i)
        printf("%d: (%lf,%lf)\n",i, out[i][0], out[i][1]);

    // try PortAudio function
    {
        Pa_Initialize();
        Pa_Terminate();
    }

    return 0;
}


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
        PaDeviceIndex i, nr_devs, default_input, default_output;

        Pa_Initialize();
        printf("\nPortAudio is initialized.\n");

        nr_devs = Pa_GetDeviceCount();
        default_input = Pa_GetDefaultInputDevice();
        default_output = Pa_GetDefaultOutputDevice();
        printf("Default Input: %d\n", default_input);
        printf("Default Output: %d\n", default_output);

        // list all available devices
        for(i=0; i<nr_devs; ++i){
            const PaDeviceInfo *info = Pa_GetDeviceInfo(i);
            printf("%d: %s(%d,%d) f:%lf\n", i, info->name, info->maxInputChannels,
                   info->maxOutputChannels, info->defaultSampleRate);
        }

        Pa_Terminate();
    }

    printf("End of the program\n");

    return 0;
}


// Copyright (c) 2017 Sony Corporation. All Rights Reserved.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// *WARNING*
// THIS FILE IS AUTO-GENERATED BY CODE GENERATOR.
// PLEASE DO NOT EDIT THIS FILE BY HAND!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "Validation_inference.h"
#include "Validation_parameters.h"

int main(int argc, char* argv[])
{
    if(argc != NNABLART_VALIDATION_NUM_OF_INPUT_BUFFERS + 2) {
        printf("Please specify 1 input files and a output file prefix\n");
        return -1;
    }

    // Allocate and initialize context
    void *context = nnablart_validation_allocate_context(Validation_parameters);

    // Input files.
    FILE* input0 = fopen(argv[1], "rb");
    assert(input0);
    int input_read_size0 = fread(nnablart_validation_input_buffer(context, 0), sizeof(float), NNABLART_VALIDATION_INPUT0_SIZE, input0);
    assert(input_read_size0 == NNABLART_VALIDATION_INPUT0_SIZE);
    fclose(input0);


    // Exec inference
    nnablart_validation_inference(context);
    
    // Output file.
    char* output_filename0 = malloc(strlen(argv[2]) + 10);
    sprintf(output_filename0, "%s_0.bin", argv[2]);
    FILE* output0 = fopen(output_filename0, "wb");
    assert(output0);
    int output_write_size0 = fwrite(nnablart_validation_output_buffer(context, 0), sizeof(float), NNABLART_VALIDATION_OUTPUT0_SIZE, output0);
    assert(output_write_size0 == NNABLART_VALIDATION_OUTPUT0_SIZE);
    fclose(output0);
    free(output_filename0);

    char* output_filename1 = malloc(strlen(argv[2]) + 10);
    sprintf(output_filename1, "%s_1.bin", argv[2]);
    FILE* output1 = fopen(output_filename1, "wb");
    assert(output1);
    int output_write_size1 = fwrite(nnablart_validation_output_buffer(context, 1), sizeof(float), NNABLART_VALIDATION_OUTPUT1_SIZE, output1);
    assert(output_write_size1 == NNABLART_VALIDATION_OUTPUT1_SIZE);
    fclose(output1);
    free(output_filename1);

    char* output_filename2 = malloc(strlen(argv[2]) + 10);
    sprintf(output_filename2, "%s_2.bin", argv[2]);
    FILE* output2 = fopen(output_filename2, "wb");
    assert(output2);
    int output_write_size2 = fwrite(nnablart_validation_output_buffer(context, 2), sizeof(float), NNABLART_VALIDATION_OUTPUT2_SIZE, output2);
    assert(output_write_size2 == NNABLART_VALIDATION_OUTPUT2_SIZE);
    fclose(output2);
    free(output_filename2);


    // free all context
    nnablart_validation_free_context(context);
    return 0;
}

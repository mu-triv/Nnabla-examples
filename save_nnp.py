#!/usr/bin/env python
# coding: utf-8

def _create_nnp_content(name, input, output, batchsize):
    runtime_contents = {
        'networks': [
            {'name': name,
             'batch_size': batchsize,
             'outputs': output,
             'names': input}],
        'executors': [
            {'name': 'Runtime',
             'network': name,
             'data': [k for k, _ in input.items()],
             'output':[k for k, _ in output.items()]}]}
    return runtime_contents

import nnabla.utils.save as save
def save_nnp(nnp_file_name, nn_name, input, output, batchsize):
    content = _create_nnp_content(nn_name, input, output, batchsize)
    save.save(nnp_file_name, content)
    return content

